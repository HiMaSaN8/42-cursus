/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:04:08 by ialzein           #+#    #+#             */
/*   Updated: 2024/02/15 04:29:16 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_error(void)
{
    write(2,"error\n",6);
    exit(1);
}
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
        {   
        write(1, "line40", 7);
            ft_print_error();
        }
        nbr = nbr * 10 + (str[i] - 48);
        i++;
    }
    if((flag * nbr) > 2147483647LLU || (flag * nbr) < -2147483648LLU)
    {   
        write(1, "line48", 7);
        ft_print_error();
    }
    return(flag * nbr);
}
void ft_free_all(t_stack *str, int flag_error)
{
    (void)str;
    if (flag_error == 1)
        write(2, "terror\n", 7);

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
    // Do not exit(1) here if you want to continue execution after freeing resources
}
// void ft_free_all(t_stack *str, int flag_error)
// {
//     if (flag_error == 1)
//         write(1,"terror\n",7);
//     if (str != NULL && flag_error != 1)
// 	{
// 		if (str->a != NULL)
// 			free(str->a);
// 		if (str->full_str != NULL)
// 			free(str->full_str);
//         if (str->b != NULL)
// 			free(str->b);
// 		if (str != NULL)
// 			free(str);
// 	}
// 	exit(1);
// }
void stack_parse(int c,char **v, t_stack *str)
{
    int i;

    i = 0;
    
    str->a_size = 0;
    str->b_size = 0;
    while (--c)
    {
        if (ft_count_word(v[i + 1], ' '))
            str->a_size += ft_count_word(v[i + 1], ' ');
        else
            str->a_size++;
        i++;
    }
    str->b = malloc(str->b_size * sizeof * str->b);
    if (str->b == NULL)
    {
        write(1, "line83", 7);
        ft_print_error();
    }
    str->a = malloc(str->a_size * sizeof * str->a);
    if (str->a == NULL)
    {
        write(1, "line89", 7);
        ft_print_error();
    }
}
int	arg_checker(char **v)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (v[i])
	{
		j = 0;
		if (v[i][j] == '\0')
			return (0);
		while (v[i][j] && v[i][j] == ' ')
		{
			j++;
			if (v[i][j] == '\0')
				return (0);
		}
		i++;
	}
	return (1);
}
static void data_parse(int c, char **v)
{
    int     i;
    int     j;

    i = 1;
    if (c < 2)
    {
        write(1, "line117", 7);
        ft_print_error();
    }   
    while(c > i)
    {
        j = 0;
        while(v[i][j])
        {
            if((!(ft_isdigit(v[i][j])) && (v[i][j]!= ' ') && (v[i][j] != '-'
            && v[i][j] != '+'))
            || (v[i][j] == '-' && v[i][j + 1] == '\0')
            || (v[i][j] == '+' && v[i][j + 1] == '\0')
            || (v[i][j] == '-' && v[i][j + 1] == ' ')
            || (v[i][j] == '+' && v[i][j + 1] == ' '))
            {
                write(1, "line131", 7);
                ft_print_error();
            }
            j++;
        }
        i++;
    }
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
    int duplicateFound = 0;  // Flag to indicate if a duplicate is found

    if (i == 0)
    {
        while (i < str->a_size)
        {
            j = i + 1;
            while (j < str->a_size)
            {
                if (str->a[i] == str->a[j])
                {
                    duplicateFound = 1;
                    break;  // Exit the inner loop when a duplicate is found
                }
                j++;
            }

            if (duplicateFound)
                break;  // Exit the outer loop when a duplicate is found

            i++;
        }
    }

    if (duplicateFound)
        ft_free_all(str, 1);
}
// void duplication_parse(t_stack *str)
// {
//     int i;
//     int j;

//     i = 0;
//     j = 0;
//     if (i == 0)
//     {
//         while(i < str->a_size)
//         {
//             j = i + 1;
//             while(j < str->a_size)
//             {
//                 if (str->a[i] == str->a[j])
//                    ft_free_all(str,1);
//                 j++;
//             }
//             i++;
//         }
//     }
// }
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
    while(i++ < str->a_size - 1)
    {
        k = 0;
        j = -1;
        while (j++ < str->a_size - 1)
            if (str->a[i] > str->a[j])
                k++;
        a[i] = k;
    }
    i = str->a_size;
    while(--i >= 0)
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
    ft_putendl_fd(list, 1);
}
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
            rotate(str->a, str->a_size, "down", "a");
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
int main(int c, char **v)
{
    t_stack *str;
        
    str = malloc(16384);
    if (str == NULL)
        return(exit(1),0);
    if(v[1] == NULL || !v[1][0] || arg_checker(v) == 0)
            write(1,"ibrahim\n",8);
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
