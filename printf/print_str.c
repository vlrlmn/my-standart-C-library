/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:53:59 by vlomakin          #+#    #+#             */
/*   Updated: 2023/08/01 13:46:22 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
			str = "(null)";
	while (*str)
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}
