/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:41:51 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/19 11:20:47 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
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
// 	t_list *cpy = list;
// 	while (cpy)
// 	{
// 		printf("%i\n", *(int *)(cpy->content));
// 		cpy = cpy->next;
// 	}
// }