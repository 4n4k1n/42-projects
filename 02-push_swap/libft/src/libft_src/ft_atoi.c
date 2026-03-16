/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:12:33 by anakin            #+#    #+#             */
/*   Updated: 2025/06/08 05:57:25 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// converts a number from a given string into a int number
// handles integer overflow
// use long int for edge case

#include "libft.h"

long	ft_atoi(const char *nptr)
{
	long	number;
	int		sign;

	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		sign = 1 - 2 * (*(nptr++) == '-');
	number = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		number = (number * 10) + ((*(nptr++) - '0') * sign);
		if (number > INT_MAX)
			return (number);
	}
	return (number);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
// 	 char *str = "-2147483699";

// 	 printf("atoi	= %d\n", atoi(str));
// 	 printf("ft_atoi = %d\n", ft_atoi(str));
// 	 return (0);
// }
