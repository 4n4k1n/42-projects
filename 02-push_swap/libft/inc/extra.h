/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:19:22 by apregitz          #+#    #+#             */
/*   Updated: 2025/06/10 11:14:00 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_H
# define EXTRA_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_dw_data
{
	int		count;
	int		active;
	char	quote_type;
	int		i;
	int		escaped;
}			t_cw_data;

typedef struct s_aw_data
{
	int		i;
	int		j;
	char	quote_type;
	char	*arr;
	int		escaped;
	int		len;
}			t_aw_data;

char		*ft_strrev(char *string);
char		*smash(const char **words, char seperator, size_t count);
int			ft_swp(void *arr1, void *arr2, size_t size);
ssize_t		ft_strclen(const char *str, char ch);

// ft_splitq utils
char		*alloc_word_q(const char **s, char c);
const char	*get_word_index_q(const char *s, char c);
int			count_words_q(char const *s, char c);
void		ft_free_splitq(char **arr, int count);
int			is_quote(char c);
char		**ft_splitq(char const *s, char c);

#endif