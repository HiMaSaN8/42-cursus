/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:37:25 by ialzein           #+#    #+#             */
/*   Updated: 2023/08/27 21:44:38 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int a, size_t	d)
{
	size_t	j;

	j = 0;
	while (j < d)
	{
		*(unsigned char *)(b + j++) = (unsigned char) a;
	}
	return (b);
}
