/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:15:43 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/10 11:20:37 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(int ac, char **av)
{
	t_data	*data;

	data = get_data();
	data->ac = ac;
	data->av = av;
	if (!valid_input(data))
		ft_exit(1);
	data->words_count = count_numbers(data);
	data->stack_a.size = data->words_count;
	if (data->words_count < 1)
		ft_exit(1);
	alloc_args(data);
	is_unique(data);
	index_llist(data);
	return (1);
}
