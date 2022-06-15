/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:52:47 by avillar           #+#    #+#             */
/*   Updated: 2022/06/15 10:19:19 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_chunk{
	int				size;
	int				min;
	int				max;
	struct s_chunk	*next;
}				t_chunk;

typedef struct s_swap{
	int		*a;
	int		*b;
	int		asize;
	int		bsize;
	int		bini_size;
	int		aini_size;
	t_chunk	*bchunk;
	t_chunk	*achunk;
}				t_swap;

typedef struct s_split{
	int	i;
	int	j;
	int	len;
}				t_split;

//ft_split.c
int		countcase(char const *s, char c);
int		sizel(char const *s, int i, char c);
void	fill_tab(char const *s, char c, int x, char *dst);
int		skipc(const char *s, char c, int i);
char	**ft_split(char const *s, char c);

//parsing.c
int		parse_check(char *str);
int		parse_nodup(t_swap *swap);
int		ft_newsize(t_swap *swap, char c);
int		check_max(char **str);

//ft_swap1.c
void	sa(t_swap *swap);
void	sb(t_swap *swap);
void	ss(t_swap *swap);
void	ra(t_swap *swap);
void	pb(t_swap *swap);

//ft_swap2.c
void	pdown_b(t_swap *swap);
void	pdown_a(t_swap *swap);
void	pup_a(t_swap *swap);
void	pup_b(t_swap *swap);
void	pa(t_swap *swap);

//ft_swap3.c
void	rb(t_swap *swap);
void	rr(t_swap *swap);
void	rra(t_swap *swap);
void	rrb(t_swap *swap);
void	rrr(t_swap *swap);

//fichier utils1.c
long	ft_atoi(const char *str);
void	init_split(t_split *split, const char *s, char c);
int		ft_tablen(char **tab);
t_swap	*parse(char *str);
void	init_swap(t_swap *swap, int *a, int size);

//utils2.c
int		*remalloc(int *src, int nsize, int bsize);
void	ft_swap(int	*a, int *b);
int		fact_sort(int *tab, int size);

//utils3.c
int		*ft_numtabcpy(int *src, int size);
int		catchmid(int *tab, int size);
int		find_min(int *x, int size);
void	free_swap(t_swap *swap);

//is_sorted.c
int		is_sorted(int *tab, int size);
int		is_rev_sorted(int *tab, int size);
int		next_isrevsort(int *tab, int size);
int		next_issorted(int *tab, int size);
int		f_sorta(t_swap *swap);

//ft_struct.c
t_chunk	*ft_lstnew(int min, int max, int size);
void	ft_lstadd_front(t_chunk **alst, t_chunk *new);
t_chunk	*ft_lstlast(t_chunk *lst);
void	ft_lstadd_back(t_chunk **alst, t_chunk *new);
void	ft_lstclear(t_chunk **lst);

//ft_struct_utils.c
void	ft_printfchunk(t_chunk *chunk);
void	new_chunk(t_swap *swap, int max, int size);
void	ft_lstdel_first(t_chunk **alst);

//ft_check_data.c
int		find_max(int *tab, int size);
int		find_nearest(t_swap *swap, int max);
int		ft_hereis(int *tab, int max, int size);
void	ft_update_chunk(int *tab, t_chunk *chunk);

//b_chunk.c
int		ft_hereismore(int *tab, int max, int size);
void	move_morethan(t_swap *swap, int mid);
void	ft_size2(t_swap *swap);
void	chunk_pa(t_swap *swap);
int		f_sortb(t_swap *swap);

//a_chunk.c
void	move_lessthan(t_swap *swap, int mid);
void	move_lessthan2(t_swap *swap, int mid);
void	chunk_pb(t_swap *swap);
void	new_achunk(t_swap *swap, int max, int size);
void	ft_size2a(t_swap *swap);

//ft_sort.c
void	sort_3a(t_swap *swap);
void	sort_5a(t_swap *swap);
void	algo_manage(t_swap *swap);
void	algo1(t_swap *swap);

//ft_push.c
void	s_to_ss(t_swap *swap, int num);
void	push_b_toa(t_swap *swap);
void	a_to_b(t_swap *swap);
void	b_to_a(t_swap *swap);

#endif