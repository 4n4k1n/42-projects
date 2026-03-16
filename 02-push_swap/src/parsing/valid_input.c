/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:15:52 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/10 11:20:52 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_set(const char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!((arg[i] >= '0' && arg[i] <= '9') || arg[i] == ' ' \
		|| arg[i] == '-' || arg[i] == '+'))
			return (0);
		i++;
	}
	return (1);
}

int	valid_input(t_data *data)
{
	int	i;

	i = 0;
	while (++i < data->ac)
	{
		if (!valid_set(data->av[i]))
			return (0);
	}
	return (1);
}
