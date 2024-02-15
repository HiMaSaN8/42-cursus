/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:38:05 by ialzein           #+#    #+#             */
/*   Updated: 2024/02/15 10:43:44 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(char *move, int *stack, int size)
{
    int temp;
    if (size <= 0)
        return ;
    temp = stack[0];
    stack[0] = stack[1];
    stack[1] = temp;
    ft_putendl_fd(move, 1);
}
void push(char *move, t_stack *str)
{
    int temp;
    if (ft_strncmp(move, "pa", 3) == 0)
    {
        if (str->b_size <= 0)
            return ;
        temp = str->b[0];
        ft_memmove(str->a + 1, str->a, sizeof(int) * str->a_size);
        str->a[0] = temp;
        str->b_size--;
        ft_memmove(str->b, str->b + 1, sizeof(int) * str->b_size);
        str->a_size++;
    }
    if (ft_strncmp(move, "pb", 3) == 0)
    {
        if (str->a_size <= 0)
            return ;
        temp = str->a[0];
        ft_memmove(str->b + 1, str->b, sizeof(int) * str->b_size);
        str->b[0] = temp;
        str->a_size--;
        ft_memmove(str->a, str->a + 1, sizeof(int) * str->a_size);
        str->b_size++;
    }
    ft_putendl_fd(move, 1);
}
void rotate(int *array, int size, char *direction, char *list)
{
    int temp;

    if (size < 0)
        return ;
    if (ft_strncmp (direction, "up", 3) == 0)
    {
        temp = array[0];
        ft_memmove(array, array + 1, sizeof(int) * (size - 1));
        array[size - 1] = temp;
        write(1, "r", 1);
    }
    if (ft_strncmp (direction, "down", 5) == 0)
    {
        temp = array[size - 1];
        ft_memmove(array + 1, array, sizeof(int) * (size - 1));
        array[0] = temp;
        write(1, "rr", 2);
    }
    ft_putendl_fd(list, 1);
}
