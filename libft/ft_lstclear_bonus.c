/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:48:51 by egrisel           #+#    #+#             */
/*   Updated: 2025/04/30 10:46:27 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur_node;
	t_list	*temp_node;

	cur_node = *lst;
	if (!cur_node)
	{
		return ;
	}
	while (cur_node)
	{
		temp_node = cur_node;
		cur_node = cur_node->next;
		ft_lstdelone(temp_node, del);
	}
	*lst = NULL;
}
