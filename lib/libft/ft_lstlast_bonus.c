/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:43:33 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/19 11:20:29 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
		}
	}
	return (lst);
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
// 	printf("The last node is %i\n", *(int *)ft_lstlast(list)->content);
// }