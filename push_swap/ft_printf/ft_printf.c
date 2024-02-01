/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 06:11:28 by ialzein           #+#    #+#             */
/*   Updated: 2023/11/29 18:29:15 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	category(const char *str, va_list arg)
{
	int	x;

	x = 0;
	if (str[x] == 'c')
		x += printc(va_arg(arg, int));
	else if (str[x] == 's')
		x += prints(va_arg(arg, char *));
	else if (str[x] == 'u')
		x += printu(va_arg(arg, unsigned int));
	else if (str[x] == 'd' || str[x] == 'i')
		x += printdi(va_arg(arg, int));
	else if (str[x] == 'x')
		x += printx(va_arg(arg, unsigned int));
	else if (str[x] == 'X')
		x += printxx(va_arg(arg, unsigned int));
	else if (str[x] == 'p')
	{
		x += prints("0x");
		x += printp(va_arg(arg, unsigned long long));
	}
	else if (str[x++] == '%')
		printc('%');
	return (x);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		x;

	i = 0;
	x = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			x += category (&format[i + 1], arg);
			i++;
		}
		else
			x += printc(format[i]);
		i++;
	}
	va_end(arg);
	return (x);
}
