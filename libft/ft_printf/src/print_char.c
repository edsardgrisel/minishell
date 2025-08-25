/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:43:19 by edsardgrise       #+#    #+#             */
/*   Updated: 2025/06/25 16:01:29 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	print_char(va_list args)
{
	unsigned char	char_to_print;

	char_to_print = (unsigned char) va_arg(args, int);
	return (write(1, &char_to_print, 1));
}
