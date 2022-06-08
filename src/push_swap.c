/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 08:48:41 by avillar           #+#    #+#             */
/*   Updated: 2022/06/08 12:23:34 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	b_to_a(t_swap *swap)
{
	if (swap->chunk)
	{
		if (is_rev_sorted(swap->b, swap->chunk->size) == 0)
			chunk_pb(swap);
		else if (swap->chunk->size <= 2)
			ft_size2(swap);
		else
		{
			move_morethan(swap, catchmid(f_sortb(swap), swap->chunk->size));
		}
		b_to_a(swap);
	}
}

void	move_lessthan(t_swap *swap, int mid)
{
	int	i;

	i = 0;
	while (ft_hereis(swap->a, mid, swap->asize) == 0)
	{
		if (swap->a[0] < mid)
		{
			i++;
			pb(swap);
		}
		else if (swap->a[swap->asize - 1] < mid)
		{
			i++;
			rra(swap);
			pb(swap);
		}
		else if (find_nearest(swap, mid) == 0)
			ra(swap);
		else
			rra(swap);
	}
	new_chunk(swap, find_max(swap->b, i), i);
}

void	algo1(t_swap *swap)
{
	int	mid;
	int	i;

	i = 0;
	i++;
	i--;
	//while (is_sorted(swap->a, swap->asize) == 1 && swap->bsize != 0)
	//{
		while (swap->asize > 2)
		{
			mid = catchmid(fact_sort(swap->a, swap->asize), swap->asize);
			move_lessthan(swap, mid);
		}
		if (swap->asize == 2 && is_sorted(swap->a, swap->asize) == 1)
			sa(swap);
		b_to_a(swap);
	//}








////////////////////////////////////////////////////////////////////////
/*	i = 0;
	while (i < swap->asize)
	{
		ft_printf("a -> %d\n", swap->a[i]);
		i++;
	}
	ft_printf("\n\n\n");
	i = 0;
	while (i < swap->bsize)
	{
		ft_printf("b -> %d\n", swap->b[i]);
		i++;
	}
	ft_printflst(swap);*/
}

int	main(int argc, char **argv)
{
	t_swap	swap;

	if (argc < 2)
		return (1);
	swap = parse(argv[1]);
	if (parse_check(argv[1]) == 1 || parse_nodup(&swap) == 1)
		return (1);
	if (is_sorted(swap.a, swap.asize) == 0)
		return (0);
	algo1(&swap);
	return (0);
}