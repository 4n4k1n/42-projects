/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_unique.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:15:38 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/08 06:10:24 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_unique(t_data *data)
{
	t_llist	*temp1;
	t_llist	*temp2;

	temp1 = data->stack_a.head;
	while (temp1)
	{
		temp2 = data->stack_a.head;
		while (temp2)
		{
			if (temp1 != temp2 && temp1->num == temp2->num)
				ft_exit(1);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (1);
}
