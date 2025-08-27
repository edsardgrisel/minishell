/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:18:49 by egrisel           #+#    #+#             */
/*   Updated: 2025/08/27 14:05:07 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdio.h>

int	is_single_token(char *str)
{
	return (str != NULL);
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
	return (0);
}


/// @brief token list created to make for easy dynamic expansion
/// @param str 
/// @return 
t_token	*tokenize(char *str)
{
	t_token_list	token_list;
	int				i;
	int				tokens_idx;

	token_list.tokens = ft_calloc(TOKENS_SIZE, sizeof(t_token));
	if (token_list.tokens == NULL)
		return (NULL);
	tokens_idx = 0;
	i = 1;
	while (1)
	{
		if (token_list.count == token_list.capacity)
		{
			if (realloc_token_list(&token_list) == -1)
				return (free(token_list), NULL);
		}
		get_next_token()
	}
}

// str = "ls | grep a"