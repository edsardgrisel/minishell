/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:42:46 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/19 11:49:28 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL)
		return ;
	if (del)
	{
		del(lst->content);
	}
	free(lst);
}

// void test(void *content)
// {
// 	free(content);
// }
// int main(void)
// {
// 	#include <stdio.h>
// 	t_list	*lst = NULL;
// 	t_list *node1 = ft_lstnew(ft_strdup("HELLO"));
// 	t_list *node2 = ft_lstnew(ft_strdup("BYE"));
// 	ft_lstadd_back(&lst, node1);
// 	ft_lstadd_back(&lst, node2);
// 	t_list *cpy = lst;
// 	while (cpy)
// 	{
// 		printf("%s\n", (char *)(cpy->content));
// 		cpy = cpy->next;
// 	}
// 	ft_lstdelone(node2, test);
// 	cpy = lst;
// 	while (cpy)
// 	{
// 		printf("%s\n", (char *)(cpy->content));
// 		cpy = cpy->next;
// 	}
// }