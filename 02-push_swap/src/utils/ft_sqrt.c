/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:16:25 by apregitz          #+#    #+#             */
/*   Updated: 2025/05/27 20:44:15 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	ft_iterative_power(int nb, int power)
// {
// 	int	result;

// 	if (power < 0)
// 		return (0);
// 	else if (power == 0)
// 		return (1);
// 	result = nb;
// 	while (power > 1)
// 	{
// 		result = result * nb;
// 		power--;
// 	}
// 	return (result);
// }

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}
