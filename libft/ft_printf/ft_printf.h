/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:03:05 by egrisel           #+#    #+#             */
/*   Updated: 2025/05/16 17:28:45 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_printf(const char *str, ...);
int	print_char(va_list args);
int	print_str(va_list args);
int	print_lowercase_hex(va_list args);
int	print_uppercase_hex(va_list args);
int	print_number(va_list args);
int	print_pointer(va_list args);
int	print_unsigned_number(va_list args);
