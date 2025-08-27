/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:18:49 by egrisel           #+#    #+#             */
/*   Updated: 2025/08/27 17:07:44 by egrisel          ###   ########.fr       */
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

char	*get_next_token(char *str, int *i)
{
	int	starting_i;
	int	in_single_quote;
	int	in_double_quote;

	while (is_space(str[*i]))
		(*i)++;

	in_single_quote = 0;
	in_double_quote = 0;
	starting_i = *i;
	while (1)
	{
		if (!in_double_quote && !in_single_quote && (is_operator(str[*i]) || is_space(str[*i])))
			return (ft_strndup(&(str[starting_i]), *i - starting_i + 1));
		(*i)++;
	}
}

void	clear_token_list_tokens(t_token_list token_list)
{
	int	i;

	i = 0;
	while (i < token_list.count)
	{
		free(token_list.tokens[i].value);
		i++;
	}
}


/// @brief token list created to make for easy dynamic expansion
/// @param str 
/// @return 
t_token	*tokenize(char *str)
{
	t_token_list	token_list;
	int				str_idx;
	int				tokens_idx;
	int				str_len;
	char			*cur_token;

	token_list.tokens = ft_calloc(TOKENS_SIZE, sizeof(t_token));
	token_list.capacity = TOKENS_SIZE;
	token_list.count = 0;

	if (token_list.tokens == NULL)
		return (NULL);
	tokens_idx = 0;
	str_idx = 0;
	str_len = ft_strlen(str);
	while (str_idx < str_len)
	{
		if (token_list.count == token_list.capacity)
		{
			if (realloc_token_list_tokens(&token_list) == -1)
				return (free(token_list.tokens), NULL);
		}
		cur_token = get_next_token(str, &str_idx);
		if (cur_token == NULL)
			clear_token_list_tokens(token_list);
		token_list.tokens[token_list.count++].value = cur_token; 
	}
	return (token_list.tokens);
}

// ls | grep a"