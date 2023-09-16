/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ib_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 03:14:27 by ialzein           #+#    #+#             */
/*   Updated: 2023/09/14 03:43:05 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printx(unsigned int d)
{
	char	*x;
	int		c;

	c = 0;
	x = "0123456789abcdef";
	if (d >= 16)
	{
		c += printx(d / 16);
		c += printx(d % 16);
	}
	else
	{
		c += printc(x[d]);
	}
	return (c);
}

int	printp(unsigned long long d)
{
	char	*x;
	int		c;

	c = 0;
	x = "0123456789abcdef";
	if (d >= 16)
	{
		c += printp(d / 16);
		c += printp(d % 16);
	}
	else
	{
		c += printc(x[d]);
	}
	return (c);
}
