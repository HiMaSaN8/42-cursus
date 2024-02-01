/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:04:08 by ialzein           #+#    #+#             */
/*   Updated: 2024/02/01 10:22:54 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi_with_error(const char *str)
{
    int					i;
	int					flag;
	unsigned long long	nbr;

	i = 0;
	nbr = 0;
	flag = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		flag = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
    while(str[i])
    {
        if(!ft_isdigit(str[i]))
            ft_print_error();
        nbr = nbr * 10 + (str[i] - 48);
        i++;
    }
    if((flag * nbr) > 2147483647 || (flag * nbr) < -2147483648)
        ft_print_error();
    return(flag * nbr);
}
void ft_print_error(void)
{
    write(2,"error\n",6);
    exit(1);
}
void ft_free_all(t_stack *str, int flag_error)
{
    if (flag_error == 1)
        write(2,"error\n",6);
    if (str != NULL && flag_error != 1)
	{
		if (str->a != NULL)
			free(str->a);
		if (str->full_str != NULL)
			free(str->full_str);
        if (str->b != NULL)
			free(str->b);
		if (str != NULL)
			free(str);
	}
	exit(1);
}
void stack_parse(int c,char **v, t_stack *str)
{
    int i;

    i = 0;
    
    str->a_size = 0;
    str->b_size = 0;
    while (--c)
    {
        if (countword (v[i + 1], ' '))
            str->a_size += countword(v[i + 1], ' ');
        str->a_size++;
        i++;
    }
    str->a = malloc(str->a_size * sizeof(t_stack));
    if (str->a == NULL)
        ft_print_error();
    str->b = malloc(str->b_size * sizeof(t_stack));
    if (str->b == NULL)
        ft_print_error();
}
static void data_parse(int c, char **v)
{
    int     i;
    int     j;

    i = 1;
    if (c < 2)
        ft_print_error();
   
    while(c > i++)
    {
        j = 0;
        if(!v[i][0] || v[i][0] == ' ')
            ft_print_error();
        while(v[i][j])
        {
            if((!(ft_isdigit(v[i][j])) && (v[i][j]!= ' ') && (v[i][j] != '-'
            && v[i][j] != '+'))
            || (v[i][j] == '-' && v[i][j + 1] == '\0')
            || (v[i][j] == '+' && v[i][j + 1] == '\0')
            || (v[i][j] == '-' && v[i][j + 1] == ' ')
            || (v[i][j] == '+' && v[i][j + 1] == ' '))
                ft_print_error();
            j++;
        }
    }
}
static void join_arguments(int c, char **v, t_stack *str)
{
    int i;
    char str_temp;
    char temp;
    
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
    ft_putendl_fd(list, 1)
}
void sort_three(t_stack *str)
{
    if(str->a[2] != 2)
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
    
}
int main(int c, char **v)
{
    t_stack *str;
    
    str = malloc(sizeof(t_stack));
    if (str = NULL)
        return(exit(1),0);
    data_parse(c,v);
    stack_parse(c, v, str);
    join_arguments(c, v, str);
    duplication_parse(str);
    sorted_parse(str);
    sort(str);
    if (str->a_size == 2 && s->a[0] > str->a[1])
        swap("sa", str->a, str->a_size);
    
    
}
