/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ib_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 03:04:01 by ialzein           #+#    #+#             */
/*   Updated: 2023/09/14 03:48:50 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printc(int c)
{
	return (write(1, &c, 1));
}

int	prints(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (s[i] != '\0')
	{
		printc(s[i]);
		i++;
	}
	return (i);
}

int	printdi(int d)
{
	int	c;

	c = 0;
	if (d == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	else if (d < 0)
	{
		c += write(1, "-", 1);
		d = -d;
		c += printdi(d);
	}
	else if (d > 9)
	{
		c += printdi(d / 10);
		c += printdi(d % 10);
	}
	else
	{
		c += printc(d + 48);
	}
	return (c);
}

int	printu(unsigned int d)
{
	int	c;

	c = 0;
	if (d > 9)
	{
		c += printu(d / 10);
		c += printu(d % 10);
	}
	else
		c += printc(d + '0');
	return (c);
}

int	printxx(unsigned int d)
{
	char	*xx;
	int		c;

	c = 0;
	xx = "0123456789ABCDEF";
	if (d >= 16)
	{
		c += printxx(d / 16);
		c += printxx(d % 16);
	}
	else
	{
		c += printc(xx[d]);
	}
	return (c);
}
