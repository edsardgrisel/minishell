/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:44:04 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/19 11:19:22 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int main(void)
// {
// 	#include <stdio.h>

// 	int i = 0;
// 	t_list *list = NULL;
// 	t_list *new = NULL;
// 	while (i < 10)
// 	{
// 		int *to_place = malloc(sizeof(int));
// 		*to_place = i;
// 		new = ft_lstnew(to_place);
// 		ft_lstadd_front(&list, new);
// 		i++;
// 	}
// 	printf("%i\n", ft_lstsize(list));
// }