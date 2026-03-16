/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_cases_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:59:03 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/10 11:21:05 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_num(t_data *data)
{
	t_llist	*temp;
	int		min;

	temp = data->stack_a.head;
	min = temp->num;
	while (temp->next)
	{
		if (min > temp->next->num)
			min = temp->next->num;
		temp = temp->next;
	}
	return (min);
}

int	find_min_position(t_data *data, int min)
{
	t_llist	*temp;
	int		pos;

	temp = data->stack_a.head;
	pos = 0;
	while (temp)
	{
		if (temp->num == min)
			return (pos);
		temp = temp->next;
		pos++;
	}
	return (pos);
}

void	move_min_to_top(t_data *data, int min)
{
	int	pos;
	int	size;

	pos = find_min_position(data, min);
	size = data->stack_a.size;
	if (pos <= size / 2)
	{
		while (data->stack_a.head->num != min)
			ra();
	}
	else
	{
		while (data->stack_a.head->num != min)
			rra();
	}
}
