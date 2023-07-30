/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:13:05 by ialzein           #+#    #+#             */
/*   Updated: 2023/07/13 23:20:24 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void* ft_memmove(void *b, const void *a, size_t n)
{
	size_t i;
	char *dest;
	const char *src;
	
	i = 0;
	
	if (n == 0)
	return b;
	
	if (a == 0 && b == 0)
	return NULL;

	dest = b;
	src = a;
	if (a > b)
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
		
	}
	else
	{
		i = n;
		while (i)
		{
			dest[i - 1] = src[i - 1];
			i--;
		}
	}
	return b;
}