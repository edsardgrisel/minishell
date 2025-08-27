/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:54:02 by egrisel           #+#    #+#             */
/*   Updated: 2025/08/27 16:32:13 by egrisel          ###   ########.fr       */
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
	enum e_token_type	type;
	char				*value;
}	t_token;

typedef struct s_token_list
{
	t_token	*tokens;
	int		count;
	int		capacity;
}	t_token_list;

typedef struct s_alloced_list
{
	void					*ptr;
	struct s_alloced_list	*next;
}	t_alloced_list;

typedef struct s_ast
{
	struct s_ast	*left;
	struct s_ast	*right;

}	t_ast;

t_token	*tokenize(char *str);
void	free_double_pointer(void **ptr);
char	*ft_strndup(char *str, int n);
int	minishell(char *envp[]);