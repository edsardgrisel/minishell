/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:35:07 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/16 11:26:27 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapped_str;
	int		index;

	mapped_str = ft_strdup(s);
	if (mapped_str == 0)
		return (NULL);
	index = 0;
	while (s[index])
	{
		mapped_str[index] = f(index, s[index]);
		index++;
	}
	return (mapped_str);
}
// static char transformation_f(unsigned int n, char c)
// {
// 	n = 1;
// 	return (1 + c);
// }
// int main(void)
// {
// 	#include <stdio.h>
// 	printf("%s\n",ft_strmapi("", transformation_f));
// }