/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:05:12 by ialzein           #+#    #+#             */
/*   Updated: 2024/02/15 01:29:54 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

typedef struct s_stack
{
	int	*a;
	int	a_size;
	int	*b;
	int	b_size;
	char	*full_str;
}	t_stack;

void		rotate(int *array, int size, char *direction, char *list);
void		swap(char *move, int *stack, int size);
void 		push(char *move, t_stack *str);
void 		ft_free_all(t_stack *str, int flag_error);
void 		stack_parse(int c,char **v, t_stack *str);
void		sort(t_stack *str);
void		sort_three(t_stack *str);
void		sort_above_three(t_stack *str);
void		radix_algorithm(t_stack *str);
// void		radix_algorithm_b(t_stack *str, int b_size, int bit_size, int i);
void		duplication_parse(t_stack *str);
void		correction(t_stack *str);
int 		ft_atoi_with_error(const char *str);
int sorted_parse(t_stack *str);
int	ft_count_word(const char *s, char c);
int	arg_checker(char **v);


#endif