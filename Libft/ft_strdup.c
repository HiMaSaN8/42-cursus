/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 05:01:42 by ialzein           #+#    #+#             */
/*   Updated: 2023/07/28 04:59:40 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char* ft_strdup(const char *s)
{
	
	char* dup;
	dup = (char*)malloc (ft_strlen(s) + 1);
	int i;
	i = 0;
	if (s == NULL || !dup)
		return NULL;
	while (*s)
	{
		dup[i++] = *s++;
		
	}
	dup[i]='\0';
	return dup;
}