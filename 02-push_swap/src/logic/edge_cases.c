/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:33:11 by apregitz          #+#    #+#             */
/*   Updated: 2025/05/30 12:00:16 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_data *data)
{
	int	temp1;
	int	temp2;
	int	temp3;

	temp1 = data->stack_a.head->num;
	temp2 = data->stack_a.head->next->num;
	temp3 = data->stack_a.head->next->next->num;
	if (temp1 > temp2 && temp1 < temp3 && temp2 < temp3)
		sa();
	else if (temp1 > temp3 && temp2 > temp3)
	{
		sa();
		rra();
	}
	else if (temp1 > temp2 && temp2 < temp3 && temp1 > temp3)
		ra();
	else if (temp1 < temp2 && temp1 > temp3 && temp2 > temp3)
		rra();
	else if (temp1 < temp2 && temp2 > temp3 && temp1 < temp3)
	{
		sa();
		ra();
	}
}

static void	sort_four(t_data *data)
{
	int	min;

	min = min_num(data);
	move_min_to_top(data, min);
	pb();
	sort_three(data);
	pa();
}

static void	sort_five(t_data *data)
{
	int	min;

	min = min_num(data);
	move_min_to_top(data, min);
	pb();
	sort_four(data);
	pa();
}

void	edge_cases(t_data *data)
{
	if (data->stack_a.size == 2)
		sa();
	else if (data->stack_a.size == 3)
		sort_three(data);
	else if (data->stack_a.size == 4)
		sort_four(data);
	else if (data->stack_a.size == 5)
		sort_five(data);
}
