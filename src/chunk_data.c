/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:37:29 by avillar           #+#    #+#             */
/*   Updated: 2022/06/03 14:54:51 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	refresh_minmax(t_swap *swap, int num)
{
	if (num == swap->chunk->cmin->min)
		swap->chunk->cmin->min++;
	else if (num == swap->chunk->cmin->max)
		swap->chunk->cmin->max--;
	else if (num == swap->chunk->cmax->min)
		swap->chunk->cmax->min++;
	else if (num == swap->chunk->cmax->max)
		swap->chunk->cmax->max--;
}

int	find_max_ofchunk(t_swap *swap, int num)
{
	int	x;
	int	*tab;

	x = 0;
	tab = malloc(sizeof(int) * (swap->asize + 1));
	if (!tab)
		return (0);
	tab = fact_sort(swap->a, swap->asize);
	x = tab[(num + 1)* swap->chunk->size - 1];
	free (tab);
	return (x);
}

int	find_min_ofchunk(t_swap *swap, int num)
{
	int	x;
	int	*tab;

	x = 0;
	tab = malloc(sizeof(int) * (swap->asize + 1));
	if (!tab)
		return (0);
	tab = fact_sort(swap->a, swap->asize);
	x = tab[(num + 1) * swap->chunk->size - swap->chunk->size];
	free (tab);
	return (x);
}

void	chunk_data_update(t_swap *swap)
{
	swap->chunk->cmin->min = find_min(swap->a, swap->asize);
	swap->chunk->cmin->max = find_max_ofchunk(swap, swap->chunk->chunk_min);
	swap->chunk->cmax->max = find_max(swap->a, swap->asize);
	swap->chunk->cmax->min = find_min_ofchunk(swap, swap->chunk->chunk_max);
	swap->chunk->cmin->def_min = swap->chunk->cmin->min;
	swap->chunk->cmin->def_max = swap->chunk->cmin->max;
	swap->chunk->cmax->def_min = swap->chunk->cmax->min;
	swap->chunk->cmax->def_max = swap->chunk->cmax->max;
}

void	init_chunk(t_swap *swap)
{
	swap->chunk = malloc(sizeof(t_chunk) * 1);
	if (!swap->chunk)
		return ;
	swap->chunk->cmax = malloc(sizeof(t_value) * 1);
	swap->chunk->cmin = malloc(sizeof(t_value) * 1);
	if (!(swap->chunk->cmin || swap->chunk->cmax))
		return ;
	//if (swap->aini_size < )
	swap->chunk->size = swap->aini_size * 0.10;
	swap->chunk->chunk_min = 0;
	swap->chunk->chunk_max = 9;
}