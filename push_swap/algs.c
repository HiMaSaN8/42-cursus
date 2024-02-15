/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:42:45 by ialzein           #+#    #+#             */
/*   Updated: 2024/02/15 10:58:55 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void sort_three(t_stack *str)
{
    if (str->a[2] != 2)
    {
        if (str->a[0] == 2)
            rotate(str->a, str->a_size, "up", "a");
        else
            rotate(str->a, str->a_size, "down", "a");
    }
    if (str->a[0] > str->a[1])
        swap("sa", str->a, str->a_size);
}
void sort_above_three(t_stack *str)
{
    while (str->b_size <= 1)
    {
        if (str->a[0] == 0)
            push("pb", str);
        else
            rotate(str->a, str->a_size, "up", "a");
    }
    if (str->b[0] == 0)
        swap("sb", str->b, str->b_size);
    if (str->a[2] != 4)
    {
        if (str->a[0] == 4)
            rotate(str->a, str->a_size, "up", "a");
        else
            rotate(str->a, str->a_size, "down", "a");
    }
    if (str->a[0] > str->a[1])
        swap("sa", str->a, str->a_size);
    push("pa", str);
}
static void radix_algorithm_b(t_stack *str, int b_size, int bit_size, int i)
{
    while (b_size-- && i <= bit_size && !sorted_parse(str))
    {
        if(((str->b[0] >> i) & 1) == 0)
            rotate(str->b, str->b_size, "up", "b");
        else
            push("pa", str);
    }
    if(sorted_parse(str))
        while (str->b_size != 0)
            push("pa", str);
}

void radix_algorithm(t_stack *str)
{
    int i;
    int bit_size;
    int size;
    
    bit_size = 0;
    size = str->a_size;
    while (size > 1 && ++bit_size)
        size /= 2;
    i = -1;
    while (++i <= bit_size)
    {
        size = str->a_size;
        while (size-- && !sorted_parse(str))
        {
            if(((str->a[0] >> i) & 1) == 0)
                push("pb", str);
            else
                rotate(str->a, str->a_size, "up", "a");
        }
        radix_algorithm_b(str, str->b_size, bit_size, i + 1);
    }
    while (str->b_size != 0)
        push("pa", str);
}
static void join_arguments(int c, char **v, t_stack *str)
{
    int i;
    char *str_temp;
    char *temp;
    
    i = 1;
    temp = ft_strdup("");
    while (++i < c && v[i] != NULL)
    {
        str_temp = ft_strjoin(temp, v[i]);
		if (temp)
			free(temp);
		if (i != c - 1)
		{
			temp = ft_strjoin(str_temp, " ");
			if (str_temp)
				free(str_temp);
			str_temp = temp;
		}
    }
    str->full_str = ft_strdup(str_temp);
    if (str->full_str == NULL)
        ft_free_all(str,1);   
}
