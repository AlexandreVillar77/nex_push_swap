/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:25:41 by avillar           #+#    #+#             */
/*   Updated: 2022/06/03 14:55:08 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	re_order_chunk(t_swap *swap, int num)
{
	if (is_rev_sorted(swap->b, swap->bsize) == 1)
	{
		if (num == swap->chunk->chunk_min)
		{
			while (swap->b[0] != swap->chunk->cmin->def_max)
			{
				//ft_printf("num = %d\n", num);
				rrb(swap);
			}
		}
		else
		{
			while (swap->b[0] != swap->chunk->cmax->def_max)
			{
				//ft_printf("here2\n");
				rrb(swap);
			}
		}
	}
}

int		chunk_choice(t_swap *swap)
{
	if (find_nearest(swap) == 1 || find_nearest(swap) == 3)
		return (1);
	else
		return (2);
}

void	rev_sort_chunks(t_swap *swap)
{
	int	i;
	int	num;

	i = 0;
	num = swap->bsize / swap->chunk->size;
	while (i < swap->chunk->size && num > 1)
	{
		rb(swap);
		i++;
	}
}