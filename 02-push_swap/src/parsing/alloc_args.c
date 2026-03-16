/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:15:25 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/10 11:19:28 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_llist	*split_arg(char *str, t_llist *llist)
{
	int		i;
	char	**arr;
	long	temp;

	arr = ft_split(str, ' ');
	if (!arr)
		ft_exit(1);
	i = -1;
	while (arr[++i])
	{
		temp = ft_atoi(arr[i]);
		if (temp > INT_MAX)
			return (ft_free_split(arr), ft_exit(1), NULL);
		llist->num = (int)temp;
		llist = llist->next;
	}
	ft_free_split(arr);
	return (llist);
}

void	alloc_args(t_data *data)
{
	int		i;
	t_llist	*temp;

	create_llist(data->words_count, data);
	if (!data->stack_a.head)
		ft_exit(1);
	temp = data->stack_a.head;
	i = 0;
	while (++i < data->ac)
		temp = split_arg(data->av[i], temp);
}
