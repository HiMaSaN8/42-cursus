/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:22:55 by ialzein           #+#    #+#             */
/*   Updated: 2023/07/14 06:34:07 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *b, const char *a, size_t len)
{
	size_t i = 0;
	while (a[i] != '\0' && i < len -1)
	{
		b[i] = a[i];
		i++;
	}
	b[i] = '\0';
	size_t alen = 0;
	while (a[alen] != '\0')
	{
		alen++;
	}
	return alen;
}