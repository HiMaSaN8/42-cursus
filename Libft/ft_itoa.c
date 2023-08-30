/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 05:49:33 by ialzein           #+#    #+#             */
/*   Updated: 2023/08/29 03:32:15 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
	{
		digit++;
	}
	while (n != 0)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

static int	isnegative(int n)
{
	if (n < 0)
	{
		return (1);
	}
	return (0);
}

static void	check(int *x, char *y)
{
	if (*x < 0)
	{
		*y = '-';
		*x = -*x;
	}
}

char	*ft_itoa(int n)
{
	int		negative;
	int		i;
	char	*result; 

	negative = isnegative(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = malloc((digits(n) + negative + 1));
	if (!result)
		return (NULL);
	if (n == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	check (&n, &result[0]);
	i = digits(n) + negative;
	result[i] = '\0';
	while (i > negative)
	{
		result[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
// int main()
// {   

// 	printf("%s", ft_itoa(0));
// }