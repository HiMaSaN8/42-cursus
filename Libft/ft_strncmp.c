/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:19:11 by ialzein           #+#    #+#             */
/*   Updated: 2023/07/21 04:10:17 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n) {
	size_t	i;

	i = 0;
	
	while (n > 0) {
        if (s1[i] != s2[i] )
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        else if (s1[i] == '\0')
            return 0;
        
        i++;
        n--;
    }
    return 0;
}
