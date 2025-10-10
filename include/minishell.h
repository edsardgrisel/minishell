/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:54:02 by egrisel           #+#    #+#             */
/*   Updated: 2025/10/10 13:28:39 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define TOKENS_SIZE 8

#include "../lib/libft/include/libft.h"


/// @brief NONE acts as a null terminator for t_token lists. so if list[i].type
/// is NONE, it indicates that the previous token was the last element
typedef enum e_token_type
{
	TOKEN_NONE = 0,
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_REDIRECT_HEREDOC,
	TOKEN_REDIRECT_APPEND,
	// TOKEN_UNSUPPORTED,
}	t_token_type;

typedef enum e_builtin_type
{
	BUILTIN_NONE = 0,
	BUILTIN_ECHO,
	BUILTIN_CD,
	BUILTIN_PWD,
	BUILTIN_EXPORT,
	BUILTIN_UNSET,
	BUILTIN_ENV,
	BUILTIN_EXIT
}	t_builtin_type;

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
	NODE_NONE,
	NODE_CMD,
	NODE_PIPE,
	NODE_REDIRECT_IN,
	NODE_REDIRECT_OUT,
	NODE_REDIRECT_HEREDOC,
	NODE_REDIRECT_APPEND,
}	t_ast_node_type;

typedef struct s_arg_list
{
	char				*str;
	struct s_arg_list	*next;
}	t_arg_list;

/// @brief if node type is NODE_CMD, cmd_str and cmargist will exist (see below)
/// If type is a redirect that requieres a redirect file, the filename as string
/// is stored in redirect file
/// @param cmd_str is the string deliminated with spaces of the
/// command and the args. This can be easily passed as string to the pipex part.
/// E.g "echo -n hello"
/// @param redirect_file if type NODE_REDIRECT redirect_file contains file path
/// @param arg_list is a t_arg_list linked list that contains each word as a
/// list element 
/// E.g echo -> -n -> hello
typedef struct s_ast_node
{
	t_ast_node_type		node_type;
	char				*cmd_str;
	char				**cmd_list;
	char				*redirect_file;
	char				*heredoc_delim;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
	struct s_ast_node	*parent;
	struct s_ast_node	*next;
	int					is_last;
	int					fd[2];
	t_builtin_type		builtin_type;

}	t_ast_node;

typedef struct s_minishell_info
{
	int			cur_exit_code;
	char		***envp;
	t_ast_node	*ast;
}	t_minishell_info;

int			minishell(t_minishell_info *minishell_info);


// Parsing
t_token		*tokenize(char *str);
t_ast_node	*parse(t_token *tokens);
t_ast_node	*parse_command(t_token *tokens, int *i);
void		cleanup_tokens(t_token *tokens);
t_ast_node	*create_node(
				t_ast_node_type node_type,
				char *cmd_str,
				char *redirect_file,
				char *heredoc_delim);
t_ast_node	*parse_pipeline(t_token *tokens, int *i);
t_ast_node	*create_ast(char *line);
t_ast_node	*add_redirect_parent_node(
				t_ast_node *root,
				t_token *cur_token,
				t_token *next_node);
t_ast_node	*parse_executable(t_token *tokens, int *i);
void		free_ast(t_ast_node *ast);

t_arg_list	*add_arg(t_arg_list *arg_list, char *arg_str);
void		free_arg_list(t_arg_list *arg_list);

// Execution
int			execution(t_minishell_info *minishell_info);
int			built_in_exec(
				t_ast_node *ast_node,
				t_minishell_info *minishell_info);
void		exec_echo(t_ast_node *ast_node, t_minishell_info *minishell_info);
void		exec_env(t_minishell_info *minishell_info);
void		exec_pwd(t_minishell_info *minishell_info);
void		exec_exit(t_ast_node *ast_node, t_minishell_info *minishell_info);
void		exec_cd(t_ast_node *ast_node, t_minishell_info *minishell_info);
void		exec_export(t_ast_node *ast_node, t_minishell_info *minishell_info);


// Helpers
char	**ft_str_list_join(char **str_list, char *str_to_join);
char		*ft_strjoin_char(char const *s1, char const *s2, char c);
char		*ft_strndup(char *str, int n);

#endif
