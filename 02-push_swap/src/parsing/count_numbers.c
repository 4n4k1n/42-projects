/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:15:32 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/10 11:19:38 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (++i < data->ac)
		count += cwords(data->av[i], ' ');
	return (count);
}
