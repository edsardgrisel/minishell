/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:42:58 by egrisel           #+#    #+#             */
/*   Updated: 2025/04/30 13:05:56 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*set_values(char *result, char const *s1, int start_i, int end_i)
{
	int	result_i;

	result_i = 0;
	while (result_i <= end_i - start_i)
	{
		result[result_i] = s1[start_i + result_i];
		result_i++;
	}
	result[result_i] = '\0';
	return (result);
}

static int	get_last_idx(char const *s1, char const *set)
{
	int	len;
	int	s1_i;

	len = ft_strlen((char *)s1);
	s1_i = len - 1;
	while (s1_i >= 0 && ft_strchr(set, s1[s1_i]) != NULL)
		s1_i--;
	if (ft_strchr(set, s1[s1_i]) != NULL)
		s1_i = -1;
	return (s1_i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s1_i;
	int		len;
	int		last;
	char	*result;

	s1_i = 0;
	last = get_last_idx(s1, set);
	if (last == -1)
		len = 0;
	else
	{
		while (ft_strchr(set, s1[s1_i]) != NULL)
			s1_i++;
		len = last - s1_i + 1;
	}
	result = ft_calloc((len + 1), sizeof(char));
	if (!result)
		return (NULL);
	set_values(result, s1, s1_i, last);
	return (result);
}
