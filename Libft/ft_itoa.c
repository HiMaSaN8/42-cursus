/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 05:49:33 by ialzein           #+#    #+#             */
/*   Updated: 2023/08/07 04:03:51 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t digits(int n)
{
	size_t digit;
	digit = 1;
	while (n /= 10)
	{
		digit ++;
	}
	return digit ;
}
char *ft_itoa(int n)
{	if (n == -2147483648)
    {
        return strdup("-2147483648");
    }
	size_t digits_num;
	digits_num = digits(n);
	int negative;
	negative = n < 0 ? 1 : 0;
	if (negative)
	{
		n = -n;
		digits_num++;
	}
	char* result = (char*)malloc(sizeof (char)* (digits_num +1));
	if(!result)
		return NULL;
	int i;
	i = digits_num -1;
	while(i >= negative)
	{
		result[i] = n%10 + '0';
		n /= 10;
		i--;
	}
	result[digits_num] = '\0';
	if (negative)
		result[0] = '-';
	return result;
	
}

