/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:22:06 by ialzein           #+#    #+#             */
/*   Updated: 2023/08/18 01:28:37 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *b, int a)
{
	int	i;

	i = 0;
	while (b[i])
		i++;
	while (i >= 0)
	{
		if (b[i] == (char)a)
			return ((char *)(b + i));
		i--;
	}
	return (NULL);
}
