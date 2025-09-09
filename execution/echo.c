/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 13:13:55 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/09 17:58:33 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <unistd.h>

// Will check if it is a valid n flag. a valid n flag is minus follow by 1 or
// more n's only
int	is_valid_n_flag(char *str, int *i)
{
	int	n_flag;

	n_flag = 0;
	if (str[(*i)++] == '-')
	{
		while (str[*i] == 'n')
		{
			n_flag = 1;
			(*i)++;
		}
		if (str[*i] == ' ' || str[*i] == '\0')
			return (n_flag);
		else
			return (0);
	}
	else
		return (0);
}

/// @brief will set n_flag and returns the string after the flag and echo
/// @param args string of args and optional n flag
/// @param is_n_flag flag pointer so exec_echo knows to print a trailing "\n" or
/// not
/// @return string to print in echo. In n_flag case, return string starting 
/// after the space after the flags. if there is no string to print, return NULL
char	*get_str_to_print_and_set_n_flag(char *args, int *n_flag)
{
	int		i;
	int		minus_encountered;
	char	*cur_args_ptr;

	i = 0;
	while(args[i] != '\0')
	{
		while (args[i] == ' ')
			i++;
		cur_args_ptr = &(args[i]);
		if (is_valid_n_flag(args, &i))
		{
			*n_flag = 1;
		}
		else
		{
			return (cur_args_ptr);
		}
	}
	return (NULL);



	// i = 0;
	// while(args[i] != '\0' && args[i] != ' ')
	// {
	// 	if (args[i] == '-')
	// 	{
	// 		if (minus_encountered)
	// 		{
	// 			*n_flag = 0;
	// 			return (args);
	// 		}
	// 		minus_encountered = 1;
	// 	}
	// 	else if (args[i] == 'n')
	// 		*n_flag = 1;
	// 	else
	// 		*n_flag = 0;
	// 	i++;
	// }
	// if (*n_flag && args[i] == ' ')
	// 	return (&(args[i + 1]));
	// if (*n_flag && args[i] == '\0')
	// 	return (&(args[i]));
	// return (args);
}

void	exec_echo(t_ast_node *ast_node, t_minishell_info *minishell_info)
{
	char	*command_and_args;
	char	*args;
	char	*str_to_print;
	int		i;
	int		n_flag;

	command_and_args = ast_node->command_and_args;
	i = 0;
	while ((command_and_args[i]) != ' ')
		i++;
	i++;
	args = &(command_and_args[i]);
	n_flag = 0;
	str_to_print = get_str_to_print_and_set_n_flag(args, &n_flag);
	if (str_to_print)
	{
		write(1, str_to_print, ft_strlen(str_to_print));
	}
	if (!n_flag)
		write(1, "\n", 1);
	// 0 exit code for success, check failure cases for echo. (write fails)
	minishell_info->cur_exit_code = 0;
}
