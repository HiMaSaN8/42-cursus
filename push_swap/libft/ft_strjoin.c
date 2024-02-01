/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:19:10 by ialzein           #+#    #+#             */
/*   Updated: 2023/08/15 20:44:04 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*out;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	if (s1 != NULL)
		i = ft_strlen(s1);
	if (s2 != NULL)
		j = ft_strlen(s2);
	out = (char *) malloc(i + j + 1);
	if (out == NULL)
		return (NULL);
	out[0] = '\0';
	if (s1 != NULL)
		ft_strlcat (out, s1, i + j + 1);
	if (s2 != NULL)
		ft_strlcat (out, s2, i + j +1);
	return (out);
}
