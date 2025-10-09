/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:43:45 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/19 11:20:26 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node_to_add;
	void	*content_to_add;

	new_list = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		content_to_add = f(lst->content);
		node_to_add = ft_lstnew(content_to_add);
		if (!node_to_add)
		{
			free(content_to_add);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node_to_add);
		lst = lst->next;
	}
	return (new_list);
}
