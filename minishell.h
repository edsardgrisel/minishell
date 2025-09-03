/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:54:02 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/03 16:47:00 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef MINISHELL_H
# define MINISHELL_H

# define TOKENS_SIZE 8

/// @brief NONE acts as a null terminator for t_token lists. so if list[i].type
/// is NONE, it indicates that the previous token was the last element
typedef enum e_token_type
{
	NONE = 0,
	WORD,
	PIPE,
	REDIRECT_IN,
	REDIRECT_OUT,
	REDIRECT_HEREDOC,
	REDIRECT_APPEND,
	UNSUPPORTED
}	t_token_type;

typedef struct s_open_quote
{
	int	single_quote;
	int	double_quote;
}	t_open_quote;

typedef struct s_token
{
	t_token_type		type;
	char				*value;
}	t_token;

// tokens last element always have .value of NULL
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

typedef enum e_ast_node_type
{
	COMMAND,
	PIPE,
	REDIRECT_IN,
	REDIRECT_OUT,
	REDIRECT_HEREDOC,
	REDIRECT_APPEND,
}	t_ast_node_type;

typedef struct s_ast_node
{
	t_ast_node_type	node_type;
	struct s_ast	*left;
	struct s_ast	*right;

}	t_ast_node;

t_token	*tokenize(char *str);
void	free_double_pointer(void **ptr);
char	*ft_strndup(char *str, int n);
int	minishell(char *envp[]);

#endif
