/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 05:51:11 by hntest2           #+#    #+#             */
/*   Updated: 2025/06/10 11:35:07 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

static size_t	get_highest_number(t_data *data, int *highest)
{
	t_llist	*temp;
	size_t	i;
	size_t	index;

	index = 0;
	i = 0;
	temp = data->stack_b.head;
	*highest = temp->num;
	while (temp->next)
	{
		if (*highest < temp->next->num)
		{
			index = i;
			*highest = temp->next->num;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

static int	push_to_stack_b(t_data *data)
{
	int	count;

	if (data->stack_a.size == 2)
		return (ra(), 1);
	count = 0;
	data->range = ft_sqrt(data->stack_a.size) * 1.6;
	while (data->stack_a.size)
	{
		if (data->stack_a.head->num <= count)
		{
			pb();
			rb();
			count++;
		}
		else if (data->stack_a.head->num <= count + data->range)
		{
			pb();
			count++;
		}
		else
			ra();
	}
	return (1);
}

static void	push_to_stack_a(t_data *data)
{
	int		highest_num;
	size_t	index;	

	while (data->stack_b.size > 0)
	{
		index = get_highest_number(data, &highest_num);
		if (index < data->stack_b.size / 2)
		{
			while (data->stack_b.head->num != highest_num)
				rb();
			pa();
		}
		else
		{
			while (data->stack_b.head->num != highest_num)
				rrb();
			pa();
		}
	}
}

void	logic(void)
{
	t_data	*data;

	data = get_data();
	data->both = 0;
	data->is_checker = 0;
	if (data->stack_a.size < 6)
		return (edge_cases(data));
	push_to_stack_b(data);
	push_to_stack_a(data);
}
