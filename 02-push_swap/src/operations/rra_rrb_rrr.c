/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:13:44 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/10 11:19:03 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(void)
{
	t_data	*data;

	data = get_data();
	if (!data->stack_a.head || !data->stack_a.head->next)
		return ;
	data->stack_a.head->prev = data->stack_a.tail;
	data->stack_a.tail->next = data->stack_a.head;
	data->stack_a.head = data->stack_a.head->prev;
	data->stack_a.tail = data->stack_a.tail->prev;
	data->stack_a.head->prev = NULL;
	data->stack_a.tail->next = NULL;
	if (!data->is_checker && !data->both)
		ft_printf("rra\n");
}

void	rrb(void)
{
	t_data	*data;

	data = get_data();
	if (!data->stack_b.head || !data->stack_b.head->next)
		return ;
	data->stack_b.head->prev = data->stack_b.tail;
	data->stack_b.tail->next = data->stack_b.head;
	data->stack_b.head = data->stack_b.head->prev;
	data->stack_b.tail = data->stack_b.tail->prev;
	data->stack_b.head->prev = NULL;
	data->stack_b.tail->next = NULL;
	if (!data->is_checker && !data->both)
		ft_printf("rrb\n");
}

void	rrr(void)
{
	t_data	*data;

	data = get_data();
	data->both = 1;
	rra();
	rrb();
	data->both = 0;
	if (!data->is_checker)
		ft_printf("rrr\n");
}
