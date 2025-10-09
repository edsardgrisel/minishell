/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:41:36 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/19 11:20:51 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (lst && new)
	{
		if (*lst == NULL)
		{
			*lst = new;
		}
		else
		{
			last_node = ft_lstlast(*lst);
			last_node->next = new;
		}
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
// 	i = 0;
// 	while (i < 10)
// 	{
// 		int *to_place = malloc(sizeof(int));
// 		*to_place = i;
// 		new = ft_lstnew(to_place);
// 		ft_lstadd_back(&list, new);
// 		i++;
// 	}
// 	t_list *cpy = list;
// 	while (cpy)
// 	{
// 		printf("%i\n", *(int *)(cpy->content));
// 		cpy = cpy->next;
// 	}
// 	// Test for empty list
// 	t_list *hello = NULL;
// 	ft_lstadd_back(&hello, new);
// 	while (hello)
// 	{
// 		printf("empty list  %i\n", *(int *)(hello->content));
// 		hello = hello->next;
// 	}
// }