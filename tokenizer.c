/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:18:49 by egrisel           #+#    #+#             */
/*   Updated: 2025/08/28 15:33:39 by egrisel          ###   ########.fr       */
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
	return (WORD);
}

/// @brief Reallocs the token_list->tokens to double the capacity.
/// @param token_list a pointer to the token_list in tokenize()
/// @return 0 on success, -1 on failure
int	realloc_token_list_tokens(t_token_list *token_list)
{
	t_token	*new_tokens;
	int		i;

	new_tokens = ft_calloc(token_list->capacity * 2, sizeof(t_token));
	if (new_tokens == NULL)
		return (-1);
	i = 0;
	while (i < token_list->capacity)
	{
		new_tokens[i] = token_list->tokens[i];
		i++;
	}
	free(token_list->tokens);
	token_list->tokens = new_tokens;
	token_list->capacity *= 2;
	return (0);
}

/// @brief Will check if the next token is an operator, if it is, sets the 
/// correct type and the value is left as null. if its a WORD, it will keep
/// looping until the end of the WORD and then set token with the value of the
/// entire word (quotes included)
/// @param str 
/// @param i 
/// @param token 
/// @return 0 on success, -1 on failure
static int	set_next_token(char *str, int *i, t_token *token)
{
	int	starting_i;

	while (is_space(str[*i]))
		(*i)++;
	token->type = get_token_type(&(str[*i]));
	if (token->type == WORD)
	{
		starting_i = *i;
		while (str[*i])
		{
			if ((is_operator(str[*i]) || is_space(str[*i])))
			{
				token->value = ft_strndup(&(str[starting_i]), *i - starting_i);
				if (token->value == NULL)
					return (-1);
			}
			(*i)++;
		}
	}
	return (0);
}

/// @brief token list created to make for easy dynamic expansion
/// @param str is line read by readline
/// @return t_tokens * list of tokens
t_token	*tokenize(char *str)
{
	t_token_list	token_list;
	int				str_idx;
	int				str_len;
	char			*cur_token;

	token_list.tokens = ft_calloc(TOKENS_SIZE + 1, sizeof(t_token));
	token_list.capacity = TOKENS_SIZE;
	token_list.count = 0;
	if (token_list.tokens == NULL)
		return (NULL);
	str_idx = 0;
	str_len = ft_strlen(str);
	while (str_idx < str_len)
	{
		if (token_list.count == token_list.capacity - 1 && realloc_token_list_tokens(&token_list) == -1)
				return (free(token_list.tokens), NULL);
		if (set_next_token(str, &str_idx, &(token_list.tokens[token_list.count++])) == -1)
			return (free(token_list.tokens), NULL);
	}
	return (token_list.tokens);
}

// ls | grep a" 