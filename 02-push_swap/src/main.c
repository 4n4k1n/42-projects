/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:16:38 by apregitz          #+#    #+#             */
/*   Updated: 2025/05/29 11:28:10 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_llist(t_llist *temp)
{
	int	i;

	i = 0;
	while (temp)
	{
		i = -1;
		while (++i <= temp->num)
			write(1, "-", 1);
		write(1, "\n", 1);
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	if (!parsing(ac, av))
		ft_exit(1);
	if (is_sorted())
		return (0);
	logic();
	ft_free();
	return (0);
}
