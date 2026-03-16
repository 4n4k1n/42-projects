/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:05:17 by hntest2           #+#    #+#             */
/*   Updated: 2025/06/10 11:22:24 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

static t_gcll_data	*get_gcll_data(void)
{
	static t_gcll_data	data;

	return (&data);
}

void	*ft_add_to_gc(void *ptr)
{
	t_gcll_data	*data;
	t_gcll		*node;

	if (!ptr)
		return (NULL);
	data = get_gcll_data();
	node = malloc(sizeof(t_gcll));
	if (!node)
		return (NULL);
	node->ptr = ptr;
	node->next = NULL;
	if (!data->head)
	{
		data->head = node;
		data->tail = node;
	}
	else
	{
		data->tail->next = node;
		data->tail = node;
	}
	return (ptr);
}

void	ft_free(void)
{
	t_gcll_data	*data;
	t_gcll		*temp;

	data = get_gcll_data();
	while (data->head)
	{
		temp = data->head->next;
		free(data->head->ptr);
		free(data->head);
		data->head = temp;
	}
	data->tail = NULL;
}

void	*ft_malloc(size_t size)
{
	t_gcll_data	*data;
	t_gcll		*node;
	void		*ptr;

	data = get_gcll_data();
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	node = malloc(sizeof(t_gcll));
	if (!node)
		return (free(ptr), NULL);
	node->ptr = ptr;
	node->next = NULL;
	if (!data->head)
	{
		data->head = node;
		data->tail = node;
	}
	else
	{
		data->tail->next = node;
		data->tail = node;
	}
	return (ptr);
}
