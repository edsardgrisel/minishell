/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:19:47 by egrisel           #+#    #+#             */
/*   Updated: 2025/06/20 15:58:36 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;
	size_t			num_bytes;

	if (size != 0 && nmemb > SIZE_MAX / size)
	{
		return (NULL);
	}
	num_bytes = nmemb * size;
	if (num_bytes == 0)
	{
		arr = malloc(1);
		if (!arr)
			return (NULL);
	}
	else
	{
		arr = malloc(num_bytes);
		if (!arr)
			return (NULL);
		ft_bzero(arr, num_bytes);
	}
	return (arr);
}
