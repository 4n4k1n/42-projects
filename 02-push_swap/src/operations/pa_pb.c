/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:09:31 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/10 11:18:33 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(void)
{
	t_data	*data;
	t_llist	*node;

	data = get_data();
	if (!data->stack_b.head)
		return ;
	node = data->stack_b.head;
	data->stack_b.head = data->stack_b.head->next;
	if (data->stack_b.head)
		data->stack_b.head->prev = NULL;
	else
		data->stack_b.tail = NULL;
	node->next = data->stack_a.head;
	node->prev = NULL;
	if (data->stack_a.head)
		data->stack_a.head->prev = node;
	else
		data->stack_a.tail = node;
	data->stack_a.head = node;
	data->stack_a.size++;
	data->stack_b.size--;
	if (!data->is_checker)
		ft_printf("pa\n");
}

void	pb(void)
{
	t_data	*data;
	t_llist	*node;

	data = get_data();
	if (!data->stack_a.head)
		return ;
	node = data->stack_a.head;
	data->stack_a.head = data->stack_a.head->next;
	if (data->stack_a.head)
		data->stack_a.head->prev = NULL;
	else
		data->stack_a.tail = NULL;
	node->next = data->stack_b.head;
	node->prev = NULL;
	if (data->stack_b.head)
		data->stack_b.head->prev = node;
	else
		data->stack_b.tail = node;
	data->stack_b.head = node;
	data->stack_a.size--;
	data->stack_b.size++;
	if (!data->is_checker)
		ft_printf("pb\n");
}
