/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:05:54 by avillar           #+#    #+#             */
/*   Updated: 2022/06/03 11:09:52 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	find_quart1(t_swap *swap)
{
	int	to;
	int	*rtn;	

	to = swap->aini_size - (swap->aini_size * 0.75);
	rtn = fact_sort(swap->a, swap->asize);
	return (rtn[to]);
}

int	make_chunk(t_swap *swap)
{

	swap->chunk_size = swap->aini_size * 0.10;
	return (0);
}

int	how_many_min(t_swap *swap, int min)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < (swap->asize / 2))
	{
		if (swap->a[i] > min)
			x++;
		i++;
	}
	while (i < swap->asize)
	{
		if (swap->a[i] > min)
			y++;
		i++;
	}
	if (x > y)
		return (1);
	else
		return (2);
}

void	rb_to_rr(t_swap *swap)
{
	int	i;

	i = -1;
	while (++i < swap->asize && swap->a[i] < swap->a_quartmin)
	{
		if (swap->a[i] > swap->a_quartmin)
		{
			if (i < (swap->asize / 2) && i != 0)
				rr(swap);
			else
				rb(swap);
		}
	}
}

void	rrb_to_rrr(t_swap *swap)
{
	int	i;

	i = -1;
	while (++i < swap->asize && swap->a[i] < swap->a_quartmin)
	{
		if (swap->a[i] > swap->a_quartmin)
		{
			if (i < swap->asize / 2 && i != 0)
				rrb(swap);
			else
				rrr(swap);
		}
	}
}

void	pb_num(t_swap *swap, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pb(swap);
		i++;
	}
}
/*
make s_chunk
distance to biggest chunk et pour shortest s_chunk
choisir le plus pres et l'ennvoyer vers l'autre stack 
trier la stack depend du plus gros ou petit
refaire


4	2
7	3
5	1
8
9
6


index chunk  min = 0 et index chiunk max = 9
chunk++ 
*/
