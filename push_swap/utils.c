/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:55:06 by ialzein           #+#    #+#             */
/*   Updated: 2024/02/15 11:44:08 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
int ft_atoi_with_error(const char *inp, t_stack *str)
{
    int					i;
	int					flag;
	long long	        nbr;

	i = 0;
	nbr = 0;
	flag = 1;
	while (inp[i] == '\t' || inp[i] == '\r' || inp[i] == ' ')
		i++;
	if (inp[i] == '-' || inp[i] == '+')
    {
        if (inp[i] == '-')
		    flag = -1;
		i++;
    }
    while(inp[i])
    {
        if(nbr > 2147483647 || (flag * nbr) < -2147483648 || ft_strlen(inp) > 11)
            ft_free_all(str, 1);
        if (!(inp[i] >= '0' && inp[i] <= '9'))
            ft_free_all(str, 1);
        nbr = nbr * 10 + (inp[i] - 48);
        i++;
    }
    return(flag * nbr);
}

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
    str->a = malloc(str->a_size * sizeof * str->a);
    if (str->a == NULL)
        ft_print_error();
    str->b = malloc(str->b_size * sizeof * str->b);
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
        if(!v[i][0] || (v[i][0] && v[i][0] == ' '))
            ft_print_error(); /*here*/
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
