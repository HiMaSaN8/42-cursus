/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:04:26 by ialzein           #+#    #+#             */
/*   Updated: 2023/07/28 03:27:06 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	if (size == 0 && nmemb * size > SIZE_MAX ) 
		return NULL;
	void* ptr = malloc(nmemb * size);
	if(ptr != NULL)
	{
		ft_memset(ptr, 0, nmemb * size);
	}
	return ptr;
}