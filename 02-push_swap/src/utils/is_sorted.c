/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:16:55 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/10 11:21:53 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(void)
{
	t_data	*data;
	t_llist	*head;

	data = get_data();
	head = data->stack_a.head;
	while (head->next)
	{
		if (head->num > head->next->num)
			return (0);
		head = head->next;
	}
	return (1);
}
