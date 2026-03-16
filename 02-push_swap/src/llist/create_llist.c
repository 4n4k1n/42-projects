/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_llist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:25:46 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/10 11:16:37 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_nodes(t_llist *head)
{
	t_llist	*temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

static t_llist	*new_node(void)
{
	t_llist	*new;

	new = (t_llist *)ft_malloc(sizeof(t_llist));
	if (!new)
		return (NULL);
	new->num = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	create_llist(size_t size, t_data *data)
{
	t_llist	*new;
	t_llist	*temp;
	t_llist	*prev;
	size_t	i;

	if (size == 0)
		return ;
	i = 1;
	new = new_node();
	if (!new)
		return ;
	temp = new;
	while (i < size)
	{
		prev = temp;
		temp->next = new_node();
		if (!temp->next)
			ft_free();
		temp = temp->next;
		temp->prev = prev;
		i++;
	}
	data->stack_a.head = new;
	data->stack_a.tail = temp;
}
