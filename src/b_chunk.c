/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_chunk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:48:18 by avillar           #+#    #+#             */
/*   Updated: 2022/06/09 11:15:58 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int		ft_hereismore(int *tab, int max, int size)
{
	int	i;

	i = -1;
	while (++i < size && tab[i])
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
	while (ft_hereismore(swap->b, mid, swap->bchunk->size) == 1
		&& swap->bchunk)

	{
		if (swap->b[0] > mid)
		{
			x++;
			pa(swap);
			swap->bchunk->size--;
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
	new_achunk(swap, find_max(swap->a, x), x);
}

void	ft_size2(t_swap *swap)
{
	if (swap->bchunk->size == 1)
		pa(swap);
	else
	{
		if (swap->b[0] < swap->b[1])
			sb(swap);
		pa(swap);
		pa(swap);
	}
	ft_lstdel_first(&swap->bchunk);
}

void	chunk_pa(t_swap *swap)
{
	while (swap->bchunk->size > 0 && swap->bsize > 0)
	{
		pa(swap);
		swap->bchunk->size--;
	}
	ft_lstdel_first(&swap->bchunk);
}

int	f_sortb(t_swap *swap)
{
	int	*fact;
	int	i;
	int rtn;

	fact = ft_numtabcpy(swap->b, swap->bchunk->size);
	if (!fact)
		return (0);
	while (is_sorted(fact, swap->bchunk->size) == 1)
	{
		i = 0;
		while (i < swap->bchunk->size - 1)
		{
			if (fact[i] > fact[i + 1])
				ft_swap(&(fact[i]), &(fact[i + 1]));
			i++;
		}
	}
	rtn = (catchmid(fact, swap->bchunk->size));
	if (fact)
		free(fact);
	return (rtn);
}
