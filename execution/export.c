/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:30:05 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/23 16:42:34 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>

/// @brief Displays all the env
/// @param envp 
/// @return exit code
int	export_no_args(char **envp)
{
	int		i;
	int		j;
	int		left_len;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
		{
			if (envp[i][j] == '=')
			{
				left_len = j + 1;
				break;
			}
			j++;
		}
		write(1, "declare -x ", 11);
		write(1, envp[i], left_len);
		write(1, "\"", 1);
		write(1, &(envp[i][left_len]), ft_strlen(&(envp[i][left_len])));
		write(1, "\"\n", 2);
		i++;
	}
	return (0);
}

/// @brief Will keep going until a space that is not in a quote. e.g
/// export abc="hello world" wont split between hello and world
/// @param str 
void	loop_until_unquoted_space(char *str, int *i)
{
	int	in_single_quote;
	int	in_double_quote;

	in_single_quote = 0;
	in_double_quote = 0;
	while (str[*i])
	{
		if ((in_single_quote && str[*i] == '\'' && !in_double_quote)
			|| (in_double_quote && str[*i] == '"' && !in_single_quote))
		{
			(*i)++;
			break;
		}
		if ((!in_single_quote && !in_double_quote) && str[*i] == ' ')
			break;
		if (!in_single_quote && str[*i] == '\'')
			in_single_quote = 1;
		if (!in_double_quote && str[*i] == '"')
			in_double_quote = 1;
		(*i)++;
	}
}

char	**ft_split_export(char *str)
{
	int		len;
	int		i;
	char	**result;

	len = 0;
	i = 0;
	while (str[i])
	{
		loop_until_unquoted_space(str, &i);
		len++;
	}
	result = ft_calloc(len + 1, sizeof(char *));
	
}

/// @brief performs a split on the args and processes each env assignment
/// individually
/// @param ast_node 
/// @param minishell_info 
/// @return exit code
int	export_with_args(char *command_and_args, t_minishell_info *minishell_info)
{
	char	**args;
	
	args = ft_split_export(command_and_args);// check split for leaks
}

/// @brief 
/// check if strncmp is safe here
/// @param ast_node 
/// @param minishell_info 
void	exec_export(t_ast_node *ast_node, t_minishell_info *minishell_info)
{
	char	*command_and_args;
	int		exit_code;
	
	command_and_args = ast_node->command_and_args;
	if (ft_strncmp(command_and_args, "export", 6) == 0)
		exit_code = export_no_args(*(minishell_info->envp));
	else
		exit_code = export_with_args(command_and_args, minishell_info->envp);
		
}