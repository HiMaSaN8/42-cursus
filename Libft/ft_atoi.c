/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:38:50 by ialzein           #+#    #+#             */
/*   Updated: 2023/09/02 17:05:02 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>

// static int check(const char *str)
// {
// 	int i;
// 	char*	c;
// 	char*	d;
	
// 	d = "0";
// 	i = 0;
// 	c = "-1";
// 	if (str[i])
// 		i++;
// 	if (*str > "922337")
// 		return (-1);
// 	if (*str < "-922337")
// 		return (0);
// }
int	ft_atoi(const char *str)
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
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	
	if (flag == 1 && nbr >= 9223372036854775807u)
		return (-1);
	if (flag == -1 && nbr >= 9223372036854775808u)
		return (0);
	}
	return (nbr * flag);
}
int main()
{
	char* b;
	b = "-922337203686249812658917589172547758090";
	printf("%i\n\n",atoi(b));
	printf("%i",ft_atoi(b));
}