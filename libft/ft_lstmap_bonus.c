/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:02:20 by egrisel           #+#    #+#             */
/*   Updated: 2025/04/30 10:44:02 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur_node;
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*new_content;

	cur_node = lst;
	if (!lst)
		return (NULL);
	while (cur_node)
	{
		new_content = f(cur_node->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		if (cur_node == lst)
			new_lst = new_node;
		else
			ft_lstadd_back(&new_lst, new_node);
		cur_node = cur_node->next;
	}
	return (new_lst);
}
