/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:49:03 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/14 16:59:48 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

// int main(void)
// {
//     #include <stdio.h>
//     char s[]= "0123456789";
//     ft_bzero(s, 5);
//     printf("Using memset result: %s",s + 5);
// }