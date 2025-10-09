/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:09:59 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/10/09 12:43:06 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_env(char *envp[])
{
	char	*found;
	int		i;

	i = 0;
	while (envp[i])
	{
		found = ft_strnstr(envp[i], "PATH=", 5);
		if (found)
		{
			return (ft_strtrim(found, "PATH="));
		}
		i++;
	}
	return (NULL);
}

static char	**get_path(char *envp[])
{
	char	*raw_path;
	char	**path;

	raw_path = get_env(envp);
	if (raw_path == NULL)
		return (NULL);
	path = ft_split(raw_path, ':');
	free(raw_path);
	return (path);
}

static void	free_str_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	*find_program(char *program, char *envp[])
{
	char	**path;
	int		i;
	char	*to_check;

	if (!access(program, X_OK) && ft_strchr(program, '/'))
		return (program);
	path = get_path(envp);
	program = ft_strjoin("/", program);
	if (program == NULL || path == NULL)
		return (free_str_array(path), free(program), \
perror("Malloc error 1"), exit(errno), NULL);
	i = 0;
	while (path[i])
	{
		to_check = ft_strjoin(path[i], program);
		if (to_check == NULL)
			return (free_str_array(path), free(program), \
perror("Malloc error 2"), exit(errno), NULL);
		if (!access(to_check, X_OK))
			return (free_str_array(path), free(program), to_check);
		free(to_check);
		i++;
	}
	return (free_str_array(path), free(program), NULL);
}

void	execute_program(char *command, char *envp[])
{
	char	**args;
	char	*path;

	args = ft_split(command, ' ');
	if (args == NULL)
		exit(EXIT_FAILURE);
	path = find_program(args[0], envp);
	if (!path)
	{
		perror(args[0]);
		exit(127);
	}
	execve(path, args, envp);
	free_str_array(args);
	perror("Program failed");
	exit(errno);
}
