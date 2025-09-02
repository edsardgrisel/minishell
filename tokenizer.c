/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:18:49 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/02 15:42:00 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '&' || c == ';');
}

/// @brief Will return the enum e_token_type of the token. if no operator is
/// found, the enum is WORD
/// @param str str to check for operator
/// @return the e_token_type
enum e_token_type	get_token_type(char *str)
{
	if (str[0] == '\0')
		return (NONE);
	if (str[0] == '<')
	{
		if (str[1] == '<')
			return (REDIRECT_HEREDOC);
		return (REDIRECT_IN);
	}
	if (str[0] == '>')
	{
		if (str[1] == '>')
			return (REDIRECT_APPEND);
		return (REDIRECT_OUT);
	}
	if (str[0] == '|')
		return (PIPE);
	if (str[0] ==  '&' || str[0] == ';')
		return (UNSUPPORTED);
	return (WORD);
}

/// @brief Reallocs the token_list->tokens to double the capacity.
/// @param token_list a pointer to the token_list in tokenize()
/// @return 0 on success, -1 on failure
int	realloc_token_list_tokens(t_token_list **token_list)
{
	t_token	*new_tokens;
	int		i;

	new_tokens = ft_calloc((*token_list)->capacity * 2, sizeof(t_token));
	if (new_tokens == NULL)
		return (-1);
	i = 0;
	while (i < (*token_list)->capacity)
	{
		new_tokens[i] = (*token_list)->tokens[i];
		i++;
	}
	free((*token_list)->tokens);
	(*token_list)->tokens = new_tokens;
	(*token_list)->capacity *= 2;
	return (0);
}

void	set_open_quotes(int *open_single_quote, int *open_double_quote,
		char *str, int i)
{
	if (!(*open_single_quote) && str[i] == '\'')
		*open_single_quote = 1;
	if (!(*open_double_quote) && str[i] == '"')
		*open_double_quote = 1;
}

/// @brief loops until it reaches the end of the token. sets the *i to the index
/// of the end of the token in str so that it can be strdup afterwards to set
/// the WORD value
/// @param str 
/// @param i pointer to index in str
void	loop_until_end_of_token(char *str, int *i)
{
	t_open_quote	open_quote;

	open_quote.single_quote = 0;
	open_quote.double_quote = 0;
	while (str[*i])
	{
		if (open_quote.single_quote && str[*i] == '\'' || open_quote.double_quote && str[*i] == '"')
		{
			(*i)++;
			break;
		}
		if ((!open_quote.single_quote && !open_quote.double_quote) && (is_operator(str[*i]) || is_space(str[*i])))
			break;
		set_open_quotes(&(open_quote.single_quote), &(open_quote.double_quote), str, *i);
		(*i)++;
	}
}


/// @brief Will check if the next token is an operator, if it is, sets the 
/// correct type and the value is left as null. if its a WORD, it will keep
/// looping until the end of the WORD and then set token with the value of the
/// entire word (quotes included)
/// @param str 
/// @param i 
/// @param token 
/// @return 
static void	set_next_token(char *str, int *i, t_token *token)
{
	int	starting_i;

	token->type = get_token_type(&(str[*i]));
	if (token->type == WORD)
	{
		starting_i = *i;
		loop_until_end_of_token(str, i);
		token->value = ft_strndup(&(str[starting_i]), *i - starting_i);
	}
	else
	{
		if (token->type == PIPE || token->type == REDIRECT_IN
			|| token->type == REDIRECT_OUT)
			(*i)++;
		if (token->type == REDIRECT_APPEND || token->type == REDIRECT_HEREDOC)
			(*i) += 2;
	}

}

/// @brief will dynamically realloc token list. will read through str and fill
/// the list with tokens
/// @param str 
/// @param token_list 
/// @return -1 on realloc fail, strdup fail and UNSUPPORTED operator. else 0
int	tokenize_loop(char *str, t_token_list *token_list)
{
	int				str_idx;
	int				str_len;
	t_token			*cur_token;

	str_idx = 0;
	str_len = ft_strlen(str);

	while (str_idx < str_len)
	{
		while (is_space(str[str_idx]))
			(str_idx)++;
		if (token_list->count == token_list->capacity - 1 && realloc_token_list_tokens(&token_list) == -1)
				return (-1);
		cur_token = &(token_list->tokens[token_list->count++]);
		set_next_token(str, &str_idx, cur_token);
		if (cur_token->type == UNSUPPORTED)
		{
			printf("Error at: %s\n", cur_token->value);
			return (-1);
		}
		if (cur_token->type == WORD && cur_token->value == NULL)
			return (-1);
	}
	return (0);
}

/// @brief token list created to make for easy dynamic expansion. skips spaces
/// and sets each token using the set_next_token() function. on strdup malloc
/// failure in case of token type WORD, you free tokens and return NULL
/// @param str is line read by readline
/// @return t_tokens * list of tokens
t_token	*tokenize(char *str)
{
	t_token_list	token_list;
	char			*cur_token;
	int				tokenize_loop_status;

	token_list.tokens = ft_calloc(TOKENS_SIZE + 1, sizeof(t_token));
	if (token_list.tokens == NULL)
		return (NULL);
	token_list.capacity = TOKENS_SIZE;
	token_list.count = 0;
	tokenize_loop_status = tokenize_loop(str, &token_list);
	if (tokenize_loop_status == -1)
		return (free(token_list.tokens), NULL);
	return (token_list.tokens);
}
