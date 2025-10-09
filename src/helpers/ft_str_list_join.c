/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_list_join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:48:40 by egrisel           #+#    #+#             */
/*   Updated: 2025/10/09 15:15:22 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_str_list_join(char **str_list, char *str_to_join)
{
	int		str_list_len;
	char	**new_str_list;
	int		i;

	str_list_len = 0;
	while (str_list[str_list_len] != NULL)
		str_list_len++;
	new_str_list = ft_calloc(str_list_len + 2, sizeof(char *));
	i = 0;
	while (i < str_list_len)
	{
		new_str_list[i] = str_list[i];
		i++;
	}
	new_str_list[i] = str_to_join;
	return (new_str_list);
}