/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:48:14 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/10 11:16:09 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_operation(char *str)
{
	if (ft_strncmp("pa\n", str, 3) == 0)
		pa();
	else if (ft_strncmp("pb\n", str, 3) == 0)
		pb();
	else if (ft_strncmp("ra\n", str, 3) == 0)
		ra();
	else if (ft_strncmp("rb\n", str, 3) == 0)
		rb();
	else if (ft_strncmp("rr\n", str, 3) == 0)
		rr();
	else if (ft_strncmp("rra\n", str, 4) == 0)
		rra();
	else if (ft_strncmp("rrb\n", str, 4) == 0)
		rrb();
	else if (ft_strncmp("rrr\n", str, 4) == 0)
		rrr();
	else if (ft_strncmp("sa\n", str, 3) == 0)
		sa();
	else if (ft_strncmp("sb\n", str, 3) == 0)
		sb();
	else if (ft_strncmp("ss\n", str, 3) == 0)
		ss();
	else
		return (0);
	return (1);
}

int	compare_results(void)
{
	t_data	*data;
	t_llist	*llist;

	data = get_data();
	if (data->stack_b.head)
		return (0);
	if (!data->stack_a.head)
		return (1);
	llist = data->stack_a.head;
	while (llist->next)
	{
		if (llist->num > llist->next->num)
			return (0);
		llist = llist->next;
	}
	return (1);
}

int	sort_operations(void)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
		{
			if (compare_results())
			{
				printf("OK\n");
				return (1);
			}
			printf("KO\n");
			return (0);
		}
		if (!execute_operation(line))
		{
			printf("Error\n");
			free(line);
			ft_exit(1);
		}
		free(line);
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = get_data();
	data->is_checker = 1;
	parsing(ac, av);
	sort_operations();
	ft_exit(0);
}
