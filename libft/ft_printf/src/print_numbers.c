/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:40:20 by edsardgrise       #+#    #+#             */
/*   Updated: 2025/05/16 17:32:40 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

static int	put_number(int num)
{
	char	cur_char;
	int		chars_printed;
	long	long_num;

	chars_printed = 0;
	long_num = (long) num;
	if (num < 0)
	{
		long_num *= -1;
		chars_printed += write(1, "-", 1);
	}
	if (long_num < 10)
	{
		cur_char = '0' + long_num;
		chars_printed += write(1, &cur_char, 1);
		return (chars_printed);
	}
	chars_printed += put_number((int)(long_num / 10));
	cur_char = '0' + long_num % 10;
	chars_printed += write(1, &cur_char, 1);
	return (chars_printed);
}

int	print_number(va_list args)
{
	int	num;

	num = va_arg(args, int);
	return (put_number(num));
}

static int	put_unsigned_number(unsigned int num)
{
	char	cur_char;
	int		chars_printed;

	chars_printed = 0;
	if (num < 10)
	{
		cur_char = '0' + num;
		chars_printed += write(1, &cur_char, 1);
		return (chars_printed);
	}
	chars_printed += put_number((int)(num / 10));
	cur_char = '0' + num % 10;
	chars_printed += write(1, &cur_char, 1);
	return (chars_printed);
}

int	print_unsigned_number(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (put_unsigned_number(num));
}
