/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:23:48 by egrisel           #+#    #+#             */
/*   Updated: 2025/05/16 17:31:56 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static int	write_pointer(unsigned long long ptr, char *base)
{
	char	cur_char;
	int		chars_written;

	if (ptr < 16)
	{
		cur_char = base[ptr % 16];
		return (write(1, &cur_char, 1));
	}
	chars_written = 0;
	cur_char = base[ptr % 16];
	chars_written += write_pointer(ptr / 16, base);
	chars_written += write(1, &cur_char, 1);
	return (chars_written);
}

int	print_pointer(va_list args)
{
	unsigned long long		ptr;
	int						chars_writen;

	chars_writen = 0;
	ptr = (unsigned long long)va_arg(args, unsigned long long);
	if (ptr == 0)
	{
		return (write(1, "(nil)", 5));
	}
	chars_writen += write(1, "0x", 2);
	chars_writen += write_pointer(ptr, "0123456789abcdef");
	return (chars_writen);
}
