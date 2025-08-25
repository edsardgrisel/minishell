/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:49:54 by edsardgrise       #+#    #+#             */
/*   Updated: 2025/05/16 17:32:17 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static int	write_base_16(unsigned int num, char *base)
{
	char	cur_char;
	int		chars_written;

	if (num < 16)
	{
		cur_char = base[num % 16];
		return (write(1, &cur_char, 1));
	}
	chars_written = 0;
	cur_char = base[num % 16];
	chars_written += write_base_16(num / 16, base);
	chars_written += write(1, &cur_char, 1);
	return (chars_written);
}

int	print_lowercase_hex(va_list args)
{
	int		num;
	int		chars_writen;

	num = (unsigned int)va_arg(args, int);
	chars_writen = write_base_16(num, "0123456789abcdef");
	return (chars_writen);
}

int	print_uppercase_hex(va_list args)
{
	int		num;
	int		chars_writen;

	num = va_arg(args, int);
	chars_writen = write_base_16(num, "0123456789ABCDEF");
	return (chars_writen);
}
