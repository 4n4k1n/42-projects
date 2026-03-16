/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:15:10 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/10 11:15:21 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include <stdlib.h>

typedef struct s_gcll
{
	void			*ptr;
	struct s_gcll	*next;
}					t_gcll;

typedef struct s_gcll_data
{
	t_gcll			*head;
	t_gcll			*tail;
}					t_gcll_data;

void				ft_free(void);
void				*ft_malloc(size_t size);
void				*ft_add_to_gc(void *ptr);

#endif