/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:45:00 by edsardgrise       #+#    #+#             */
/*   Updated: 2025/05/16 17:31:19 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	print_str(va_list args)
{
	unsigned char	*str;
	int				len;
	int				chars_printed;

	len = 0;
	chars_printed = 0;
	str = va_arg(args, unsigned char *);
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (str[len])
		len++;
	return (write(1, str, len));
}
