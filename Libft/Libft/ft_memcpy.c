/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:48:42 by ialzein           #+#    #+#             */
/*   Updated: 2023/08/12 23:05:52 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void	*src, size_t	a)
{
	size_t	j;

	if (dest == NULL && src == NULL)
		return (NULL);
	j = 0;
	while (j < a)
	{
		*(unsigned char *)(dest + j) = *(unsigned char *)(src + j);
		j++;
	}
	return (dest);
}
