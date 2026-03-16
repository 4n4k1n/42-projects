/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:13:35 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/10 11:19:15 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(void)
{
	t_data	*data;

	data = get_data();
	if (!data->stack_a.head || !data->stack_a.head->next)
		return ;
	data->stack_a.head->num ^= data->stack_a.head->next->num;
	data->stack_a.head->next->num ^= data->stack_a.head->num;
	data->stack_a.head->num ^= data->stack_a.head->next->num;
	if (!data->is_checker && !data->both)
		ft_printf("sa\n");
}

void	sb(void)
{
	t_data	*data;

	data = get_data();
	if (!data->stack_b.head || !data->stack_b.head->next)
		return ;
	data->stack_b.head->num ^= data->stack_b.head->next->num;
	data->stack_b.head->next->num ^= data->stack_b.head->num;
	data->stack_b.head->num ^= data->stack_b.head->next->num;
	if (!data->is_checker && !data->both)
		ft_printf("sb\n");
}

void	ss(void)
{
	t_data	*data;

	data = get_data();
	data->both = 1;
	sa();
	sb();
	data->both = 0;
	if (!data->is_checker)
		ft_printf("ss\n");
}
