/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:49:04 by avillar           #+#    #+#             */
/*   Updated: 2022/06/15 10:02:00 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	b_to_a(t_swap *swap)
{
	if (swap->bsize < 1)
		return ;
	else if (swap->bchunk)
	{
		if (is_rev_sorted(swap->b, swap->bchunk->size) == 0)
			chunk_pa(swap);
		else if (swap->bchunk->size <= 2)
			ft_size2(swap);
		else
		{
			move_morethan(swap, f_sortb(swap));
		}
		if (swap->bsize > 0)
			b_to_a(swap);
	}
}

void	a_to_b(t_swap *swap)
{
	if (is_sorted(swap->a, swap->asize) == 0 || !swap->achunk)
		return ;
	if (swap->achunk)
	{
		if (is_sorted(swap->a, swap->achunk->size) == 0
			&& is_sorted(swap->a, swap->asize == 1))
		{
			chunk_pb(swap);
		}
		else if (swap->achunk->size <= 2)
			ft_size2a(swap);
		else if (swap->achunk->size > 0)
		{
			move_lessthan2(swap, f_sorta(swap));
		}
		a_to_b(swap);
	}
}

void	push_b_toa(t_swap *swap)
{
	while (swap->bsize > 0)
		pa(swap);
}

void	s_to_ss(t_swap *swap, int num)
{
	if ((swap->bchunk->size == 2 && swap->b[0] < swap->b[1])
		&& (swap->asize == 2 && is_sorted(swap->a, swap->asize) == 1))
		ss(swap);
	else if (num == 0)
		sa(swap);
	else if (num == 1)
		sb(swap);
}
