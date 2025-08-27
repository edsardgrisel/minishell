/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:26:47 by egrisel           #+#    #+#             */
/*   Updated: 2025/08/27 12:28:38 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief 
/// @param ptr A null terminated 2d alloced list
void	free_double_pointer(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}