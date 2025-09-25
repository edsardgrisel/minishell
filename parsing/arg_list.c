/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:03:35 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/25 15:10:50 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>

void	free_arg_list(t_arg_list *arg_list)
{
	t_arg_list	*cur_node;
	t_arg_list	*node_to_free;

	cur_node = arg_list;
	while (cur_node)
	{
		node_to_free = cur_node;
		cur_node = cur_node->next;
		free(node_to_free->str);
		free(node_to_free);
		node_to_free = NULL;
	}
}

/// @brief appends a t_arg_list node with arg_str = arg_str to arg_list
/// if arg_list is null, allocate and set the new node to arg_list
/// @param arg non alloced string that will be alloced and set to t_arg_list.arg
/// @return the head of arg_list
t_arg_list	*add_arg(t_arg_list *arg_list, char *arg_str)
{
	t_arg_list	*new_node;
	t_arg_list	*cur_node;
	char		*alloced_arg_str;

	alloced_arg_str = ft_strdup(arg_str);
	if (alloced_arg_str == NULL)
		return (NULL);
	new_node = ft_calloc(1, sizeof(t_arg_list));
	if (new_node == NULL)
		return (free(alloced_arg_str), NULL);
	new_node->str = alloced_arg_str;
	if (arg_list == NULL)
		return (new_node);
	cur_node = arg_list;
	while (cur_node->next)
		cur_node = cur_node->next;
	cur_node->next = new_node;
	return (arg_list);
}
