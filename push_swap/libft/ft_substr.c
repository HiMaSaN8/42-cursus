/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:05:27 by ialzein           #+#    #+#             */
/*   Updated: 2023/08/30 05:34:26 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;

	if (s == NULL || start < 0 || len < 0)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	out = (char *) malloc (sizeof(*s) * (len + 1));
	if (out != NULL)
	{
		ft_strlcpy(out, s + start, len + 1);
		out[len] = '\0';
	}
	return (out);
}
