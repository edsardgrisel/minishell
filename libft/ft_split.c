/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:19:26 by edsardgrise       #+#    #+#             */
/*   Updated: 2025/06/20 11:16:11 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_word_count(const char *str, char c)
{
	int	count;
	int	i;
	int	is_in_word;

	i = 0;
	count = 0;
	is_in_word = 0;
	while (str[i])
	{
		if (!is_in_word && str[i] != c)
		{
			count++;
			is_in_word = 1;
		}
		else if (is_in_word && str[i] == c)
			is_in_word = 0;
		i++;
	}
	return (count);
}

static int	set_get_len(const char *str, char c, char **res_arr, int res_arr_i)
{
	int		len;
	char	*str_to_write;
	int		write_idx;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	str_to_write = (char *) ft_calloc((len + 1), sizeof(char));
	if (!str_to_write)
		return (-1);
	write_idx = 0;
	while (write_idx < len)
	{
		str_to_write[write_idx] = str[write_idx];
		write_idx++;
	}
	str_to_write[write_idx] = '\0';
	res_arr[res_arr_i] = str_to_write;
	return (len);
}

static void	free_all(char **res_arr)
{
	int	i;

	i = 0;
	while (res_arr[i])
	{
		free(res_arr[i]);
		i++;
	}
	free(res_arr);
}

static void	set_idxs_to_zero(int *s_idx, int *res_arr_idx)
{
	*s_idx = 0;
	*res_arr_idx = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**res_arr;
	int		cur_word_len;
	int		word_count;
	int		s_idx;
	int		res_arr_idx;

	word_count = ft_word_count(s, c);
	res_arr = ft_calloc((word_count + 1), sizeof(char *));
	if (!res_arr)
		return (NULL);
	set_idxs_to_zero(&s_idx, &res_arr_idx);
	while (s[s_idx])
	{
		if (s[s_idx] != c)
		{
			cur_word_len = set_get_len(&s[s_idx], c, res_arr, res_arr_idx++);
			if (cur_word_len == -1)
				return (free_all(res_arr), NULL);
			s_idx += cur_word_len;
		}
		else
			s_idx++;
	}
	res_arr[res_arr_idx] = NULL;
	return (res_arr);
}
