/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:20:19 by avillar           #+#    #+#             */
/*   Updated: 2022/06/03 14:55:32 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	sort_a(t_swap *swap)
{
	int	min;
	int	cut;

	cut = 0;
	while (is_sorted(swap->a, swap->asize) == 1)
	{
		min = find_min(swap->a, swap->asize);
		cut++;
		topa_tob(swap, min);
	}
	while (swap->bsize > 0)
		pa(swap);
}

void	sort_b(t_swap *swap)
{
	int	max;
	int	s;

	s = 0;
	while (s < swap->chunk_size)
	{
		s++;
		max = find_max_under(swap->b, swap->bsize, swap->b_min_sort);
		topb_toa(swap, max);
	}
	while (next_issorted(swap->a, --s) == 0)
		pb(swap);
}

void	algo1(t_swap *swap)
{
	int	x;

	x = 0;
	init_chunk(swap);
	while (x < 5)
	{
		chunk_data_update(swap);
		if (chunk_choice(swap) == 1)
			chunkmin_push(swap);
		else if (chunk_choice(swap) == 2)
			chunkmax_push(swap);
		rev_sort_chunks(swap);
		x++;
	}
	/*int	i;

	i = 0;
	while (i < swap->chunk->size * x)
	{
		ft_printf("b -> %d\n", swap->b[i]);
		i++;
	}*/
}

int	main(int argc, char **argv)
{
	int		i;
	t_swap	swap;

	i = -1;
	if (argc < 2)
		return (1);
	swap = parse(argv[1]);
	if (parse_check(argv[1]) == 1 || parse_nodup(&swap) == 1)
		return (1);
	if (is_sorted(swap.a, swap.asize) == 0)
		return (0);
	algo1(&swap);
	i++;
	/*while (i < swap.asize || i < swap.bsize)
	{
		if (i < swap.asize)
			ft_printf("swap -> a = %d", swap.a[i]);
		if (i < swap.bsize)
		{
			ft_printf("  ||  swap -> b = %d", swap.b[i]);
		}
		ft_printf("\n");
		i++;
	}*/
	return (i);
}
