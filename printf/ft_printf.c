/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:16:10 by vlomakin          #+#    #+#             */
/*   Updated: 2023/07/31 17:30:20 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		count += print_pointer();
	else if (specifier == 'd')
		count += print_digit((long)va_arg(ap, int), 10);
	else if (specifier == 'i')
		count += print_integer();
	else if (specifier == 'u')
		count += print_unsigned();
	else if (specifier == 'x')
		count += print_digit((long)va_arg(ap, unsigned int), 16);
	else if (specifier == 'X')
		count += print_upper_hex();
	else if (specifier == '%')
		print_char('%');
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	int count;

// 	// count = printf("Hello %s\n", "John");
// 	// ft_printf("Written %d\n", count);
// 	// count = ft_printf("%x\n", INT_MAX);
// 	// ft_printf("Chars amount: %d\n", count);
// 	ft_printf("Hello %s, today is %d, in hex %x, char -> %c\n", "John", 27, 27, 'z');
// }