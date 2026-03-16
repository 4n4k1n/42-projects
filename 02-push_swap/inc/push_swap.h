/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:34:58 by hntest2           #+#    #+#             */
/*   Updated: 2025/06/10 11:13:11 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/inc/libft.h"

typedef struct s_llist
{
	struct s_llist	*next;
	struct s_llist	*prev;
	int				num;
	int				index;
}					t_llist;

typedef struct s_stack
{
	t_llist			*head;
	t_llist			*tail;
	size_t			size;
}					t_stack;

typedef struct s_data
{
	t_stack			stack_a;
	t_stack			stack_b;
	int				range;
	int				words_count;
	int				ac;
	char			**av;
	int				is_checker;
	int				both;
}					t_data;

// parsing
int					count_numbers(t_data *data);
int					valid_input(t_data *data);
void				alloc_args(t_data *data);
int					parsing(int ac, char **av);
int					is_unique(t_data *data);
void				index_llist(t_data *data);

// utils
t_data				*get_data(void);
void				ft_exit(int error);
int					cwords(char const *s, char c);
int					ft_atoll(char *str, t_llist *node);
int					ft_sqrt(int nb);
int					is_sorted(void);
int					min_num(t_data *data);
int					find_min_position(t_data *data, int min);
void				move_min_to_top(t_data *data, int min);

// operations
void				pa(void);
void				pb(void);
void				sa(void);
void				sb(void);
void				ss(void);
void				ra(void);
void				rb(void);
void				rr(void);
void				rra(void);
void				rrb(void);
void				rrr(void);

// llist
void				free_nodes(t_llist *head);
void				create_llist(size_t size, t_data *data);

// logic
void				logic(void);
void				edge_cases(t_data *data);

// debug
// void				print_llist(t_llist *temp);

#endif
