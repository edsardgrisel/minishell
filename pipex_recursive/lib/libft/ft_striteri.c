/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:34:33 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/14 17:34:34 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		index;

	index = 0;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}

// static void transformation_f(unsigned int n, char *c)
// {
// 	n = 1;
// 	*c += 1;
// }

// int main(void)
// {
// 	#include <stdio.h>

// 	char str[] = "abcde";

// 	ft_striteri(str, transformation_f);
// 	printf("%s\n",str);
// }