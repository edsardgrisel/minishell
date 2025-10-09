/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:42:09 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/19 11:20:43 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_to_free;
	t_list	*current_node;

	next_to_free = NULL;
	current_node = *lst;
	if (lst == NULL)
		return ;
	while (current_node)
	{
		next_to_free = current_node->next;
		ft_lstdelone(current_node, del);
		current_node = next_to_free;
	}
	*lst = NULL;
}
