/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_chunk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:48:18 by avillar           #+#    #+#             */
/*   Updated: 2022/06/08 12:22:58 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int		ft_hereismore(int *tab, int max, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (tab[i] > max)
			return (1);
	}
	return (0);
}

void	move_morethan(t_swap *swap, int mid)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (ft_hereismore(swap->b, mid, swap->chunk->size))
	{
		if (swap->b[0] > mid)
		{
			x++;
			pa(swap);
			swap->chunk->size--;
			while (i > 0)
			{
				i--;
				rrb(swap);
			}
		}
		else
		{
			i++;
			rb(swap);
		}
	}
	
}

void	ft_size2(t_swap *swap)
{
	if (swap->chunk->size == 1)
		pa(swap);
	else
	{
		if (swap->b[0] < swap->b[1])
			sb(swap);
		pa(swap);
		pa(swap);
	}
	ft_lstdel_first(&swap->chunk);
}

void	chunk_pb(t_swap *swap)
{
	while (swap->chunk->size > 0)
	{
		pa(swap);
		swap->chunk->size--;
	}
	ft_lstdel_first(&swap->chunk);
}

int	*f_sortb(t_swap *swap)
{
	int	*fact;
	int	i;

	fact = ft_numtabcpy(swap->b, swap->chunk->size);
	if (!fact)
		return (0);
	while (is_sorted(fact, swap->chunk->size) == 1)
	{
		i = 0;
		while (i < swap->chunk->size - 1)
		{
			if (fact[i] > fact[i + 1])
				ft_swap(&(fact[i]), &(fact[i + 1]));
			i++;
		}
	}
	return (fact);
}
