/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copypushswap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:04:08 by ialzein           #+#    #+#             */
/*   Updated: 2024/02/15 11:05:41 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void correction(t_stack *str)
{
    int i;
    int j;
    char    **k;

    i = 0;
    j = 0;
    k = ft_split(str->full_str, ' ');
    while(k[i] != NULL && k[i][0] != '\0')
    {
        str->a[j++] = ft_atoi_with_error(k[i++]);
        free(k[i - 1]);
    }
    free(k);
}
void duplication_parse(t_stack *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (i == 0)
    {
        while(i < str->a_size)
        {
            j = i + 1;
            while(j < str->a_size)
            {
                if (str->a[i] == str->a[j])
                    ft_free_all(str,1);
                j++;
            }
            i++;
        }
    }
}
int sorted_parse(t_stack *str)
{
    int i;

    i = 0;
    while(i < str->a_size - 1)
    {
        if(str->a[i] > str->a[i + 1])
            ft_free_all(str, 0);
        i++;
    }
    return (1);
}
void sort(t_stack *str)
{
    int i;
    int j;
    int k;
    int *a;

    i = -1;
    a = malloc(str->a_size * sizeof * a);

    if (!a)
        ft_free_all(str, 1);
    while(i++ < str->a_size)
    {
        k = 0;
        j = -1;
        while (j++ < str->a_size)
            if (str->a[i] > str->a[j])
                k++;
        a[i] = k;
    }
    i = str->a_size;
    while(i--)
        str->a[i] = a[i];
    free(a);
}


int main(int c, char **v)
{
    t_stack *str;
    
    str = malloc(sizeof(t_stack));
    if (str == NULL)
        return(exit(1),0);
    data_parse(c,v);
    stack_parse(c, v, str);
    join_arguments(c, v, str);
    duplication_parse(str);
    sorted_parse(str);
    sort(str);
    if (str->a_size == 2 && str->a[0] > str->a[1])
        swap("sa", str->a, str->a_size);
    else if (str->a_size == 3)
        sort_three(str);
    else if (str->a_size <= 5 && str->a_size >= 4)
        sort_above_three(str);
    else
        radix_algorithm(str);
    ft_free_all(str,1);
    return (0);
    
}
