/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:19:04 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/23 14:57:32 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

/// @brief will str compare until the '=' char, if key matches str before '='
/// return the pointer to the beginning of the value, else null;
/// @param key 
/// @param str 
/// @return 
char	*get_value_from_key(char *key, char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '=')
			return (&(str[i + 1]));
		if (key[i] != str[i])
			return (NULL);
		i++;
	}
	return (NULL);
}

char	*get_env(char *key, t_minishell_info *minishell_info)
{
	char	***envp;
	int		i;
	char	*result;
	
	envp = minishell_info->envp;
	i = 0;
	while(envp[i])
	{
		result = get_value_from_key(key, (*envp)[i]);
		if (result)
			return (result);
		i++;
	}
	return (NULL);
}