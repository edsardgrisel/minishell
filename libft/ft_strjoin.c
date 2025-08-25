/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:15:30 by egrisel           #+#    #+#             */
/*   Updated: 2025/06/20 12:00:27 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_1;
	int		len_2;
	char	*str;
	int		i;
	int		str_i;

	len_1 = ft_strlen((char *)s1);
	len_2 = ft_strlen((char *)s2);
	str = ft_calloc((len_1 + len_2 + 1), sizeof(char));
	if (!str)
		return (NULL);
	str_i = 0;
	i = 0;
	while (str_i < len_1)
		str[str_i++] = s1[i++];
	i = 0;
	while (str_i < len_1 + len_2)
		str[str_i++] = s2[i++];
	str[str_i] = '\0';
	return (str);
}
