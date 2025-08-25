/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:54:02 by egrisel           #+#    #+#             */
/*   Updated: 2025/08/25 16:56:53 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TOKENS_SIZE 16

enum e_token_type
{
	WORD,
	PIPE,
};

typedef struct s_token
{
	e_token_type	type;
	char			*value;
}	t_token;

typedef struct s_alloced_list
{
	void					*ptr;
	struct s_alloced_list	*next;
}	t_alloced_list;

t_token	*tokenize(int argc, char *argv[]);