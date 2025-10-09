/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:36:47 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/11 16:29:12 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	exec_pwd(t_minishell_info *minishell_info)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		minishell_info->cur_exit_code = 1; // check exit code
		perror("getcwd error\n");
		return ;
	}
	write(1, pwd, ft_strlen(pwd));
	write(1, "\n", 1);
	minishell_info->cur_exit_code = 0;
	free(pwd);
}