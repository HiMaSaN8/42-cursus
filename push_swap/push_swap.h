/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:05:12 by ialzein           #+#    #+#             */
/*   Updated: 2024/01/21 20:29:50 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

typedef struct s_stack
{
	int	*a;
	int	a_size;
	int	*b;
	int	b_size;
	char	*full_str;
}	t_stack;
#endif