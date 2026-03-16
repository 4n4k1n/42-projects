/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_llist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:01:50 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/10 11:20:27 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_llist	**create_llist_arr(t_data *data)
{
	t_llist	**nodes;
	t_llist	*temp;
	int		i;

	nodes = malloc(data->stack_a.size * sizeof(t_llist *));
	if (!nodes)
		ft_exit(1);
	temp = data->stack_a.head;
	i = 0;
	while (temp)
	{
		nodes[i] = temp;
		temp = temp->next;
		i++;
	}
	return (nodes);
}

static void	sort_llist_arr(t_llist **nodes, t_data *data)
{
	t_llist	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->stack_a.size - 1)
	{
		j = 0;
		while (j < data->stack_a.size - 1)
		{
			if (nodes[j]->num > nodes[j + 1]->num)
			{
				temp = nodes[j];
				nodes[j] = nodes[j + 1];
				nodes[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	overwrite_value_with_index(t_llist **nodes, t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->stack_a.size)
	{
		nodes[i]->num = i;
		i++;
	}
}

void	index_llist(t_data *data)
{
	t_llist	**nodes;

	if (!data->stack_a.head)
		return ;
	nodes = create_llist_arr(data);
	sort_llist_arr(nodes, data);
	overwrite_value_with_index(nodes, data);
	free(nodes);
}
