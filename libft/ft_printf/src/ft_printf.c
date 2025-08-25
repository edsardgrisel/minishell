/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:04:01 by egrisel           #+#    #+#             */
/*   Updated: 2025/05/16 17:30:53 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "../ft_printf.h"

static int	process_conversion(char c, va_list args)
{
	int	chars_printed;

	chars_printed = 0;
	if (c == 'c')
		chars_printed = print_char(args);
	else if (c == 's')
		chars_printed = print_str(args);
	else if (c == 'p')
		chars_printed = print_pointer(args);
	else if (c == 'd' || c == 'i')
		chars_printed = print_number(args);
	else if (c == 'u')
		chars_printed = print_unsigned_number(args);
	else if (c == 'x')
		chars_printed = print_lowercase_hex(args);
	else if (c == 'X')
		chars_printed = print_uppercase_hex(args);
	return (chars_printed);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		chars_printed;

	if (str == NULL)
		return (-1);
	i = 0;
	chars_printed = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				chars_printed += write(1, "%%", 1);
			else
				chars_printed += process_conversion(str[i + 1], args);
			i++;
		}
		else
			chars_printed += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (chars_printed);
}
