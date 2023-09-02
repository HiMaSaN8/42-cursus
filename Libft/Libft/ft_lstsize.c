/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 04:26:01 by ialzein           #+#    #+#             */
/*   Updated: 2023/08/18 20:17:18 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		a;
	t_list	*counter;

	a = 0;
	counter = lst;
	while (counter)
	{
		counter = counter->next;
		a++;
	}
	return (a);
}
