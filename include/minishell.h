/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:54:02 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/09 16:44:38 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef MINISHELL_H
# define MINISHELL_H

# define TOKENS_SIZE 8

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
	NODE_COMMAND,
	NODE_PIPE,
	NODE_REDIRECT_IN,
	NODE_REDIRECT_OUT,
	NODE_REDIRECT_HEREDOC,
	NODE_REDIRECT_APPEND,
}	t_ast_node_type;

/// @brief if node type is NODE_COMMAND, then command_and_args is a string with 
/// spaces between command name and the args e.g "wc -l".
/// If type is a redirect that requieres a redirect file, the filename as string
/// is stored in redirect file
typedef struct s_ast_node
{
	t_ast_node_type	node_type;
	char			*command_and_args;
	char			*redirect_file;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
	t_builtin_type		builtin_type;

}	t_ast_node;

typedef struct s_minishell_info
{
	int	cur_exit_code;
}	t_minishell_info;

int			minishell(char *envp[], t_minishell_info *minishell_info);
char		*ft_strjoin_char(char const *s1, char const *s2, char c);
char		*ft_strndup(char *str, int n);

// Parsing
t_token		*tokenize(char *str);
t_ast_node	*parse(t_token *tokens);
t_ast_node	*parse_command(t_token *tokens, int *i);
void		cleanup_tokens(t_token *tokens);
t_ast_node	*create_node(
	t_ast_node_type node_type,
	char *command_and_args,
	char *redirect_file
);
void	clear_ast(t_ast_node *root);
t_ast_node	*parse_pipeline(t_token *tokens, int *i);
t_ast_node	*create_ast(char *line);

// Execution
int	execution(t_ast_node *ast_root, t_minishell_info *minishell_info);
int	built_in_exec(t_ast_node *ast_node, t_minishell_info *minishell_info);
void	exec_echo(t_ast_node *ast_node, t_minishell_info *minishell_info);

#endif
