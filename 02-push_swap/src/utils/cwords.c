/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:16:08 by apregitz          #+#    #+#             */
/*   Updated: 2025/05/26 10:16:09 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	cwords(char const *s, char c)
{
	int	count;
	int	active;

	active = 0;
	count = 0;
	while (*s)
	{
		if (!active && *s != c)
		{
			active = 1;
			count++;
		}
		else if (active && *s == c)
			active = 0;
		s++;
	}
	return (count);
}
