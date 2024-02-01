/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 05:40:08 by ialzein           #+#    #+#             */
/*   Updated: 2023/08/25 06:12:46 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*counter;

	if (!lst)
		return (0);
	counter = lst;
	while (counter -> next != NULL)
		counter = counter->next;
	return (counter);
}
