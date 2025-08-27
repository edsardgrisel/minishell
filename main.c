/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:41:53 by egrisel           #+#    #+#             */
/*   Updated: 2025/08/27 13:34:31 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

/// @brief Loops and calls minishell repeatedly. if failure returned, return
/// EXIT_FAILURE. It is the reponsability of minishell() to perror the reason
/// @param argc 
/// @param argv 
/// @param envp 
/// @return 
int	main(int argc, char *argv[], char *envp[])
{

	(void)argc;
	(void)argv;
	while (1)
	{
		if (minishell(envp) == EXIT_FAILURE)
		{
			return (EXIT_FAILURE);
		}
	}
}