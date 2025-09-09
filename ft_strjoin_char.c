/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:16:06 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/09 14:50:56 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

// joins s1 and s2 with char c in between them.
char	*ft_strjoin_char(char const *s1, char const *s2, char c)
{
	int		len_1;
	int		len_2;
	char	*str;
	int		i;
	int		str_i;

	len_1 = ft_strlen((char *)s1);
	len_2 = ft_strlen((char *)s2);
	str = ft_calloc((len_1 + len_2 + 2), sizeof(char));
	if (!str)
		return (NULL);
	str_i = 0;
	i = 0;
	while (str_i < len_1)
		str[str_i++] = s1[i++];
	str[str_i++] = c;
	i = 0;
	while (str_i < len_1 + len_2 + 1)
		str[str_i++] = s2[i++];
	return (str);
}
