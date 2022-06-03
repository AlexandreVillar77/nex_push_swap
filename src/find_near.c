/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_near.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:42:26 by avillar           #+#    #+#             */
/*   Updated: 2022/06/03 14:16:45 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	find_nearest(t_swap *swap)
{
	int	i;
	int	x;
	int	max[2];
	int	min[2];

	i = -1;
	x = swap->asize - 1;
	max[0] = swap->chunk->cmax->min;
	max[1] = swap->chunk->cmax->max;
	min[0] = swap->chunk->cmin->min;
	min[1] = swap->chunk->cmin->max;
	while (++i < swap->asize / 2 && x > swap->asize / 2)
	{
		if (swap->a[i] == min[0] || swap->a[i] == min[1])
			return (1);
		if (swap->a[i] == max[0] || swap->a[i] == max[1])
			return (2);
		if (swap->a[x] == min[0] || swap->a[x] == min[1])
			return (3);
		if (swap->a[x] == max[0] || swap->a[x] == max[1])
			return (4);
		x--;
	}
	return (0);
}

int	find_nearest_min(t_swap *swap)
{
	int	i;
	int	x;
	int	min[2];

	i = -1;
	x = swap->asize - 1;
	min[0] = swap->chunk->cmin->min;
	min[1] = swap->chunk->cmin->max;
	while (++i < swap->asize / 2 && x > swap->asize / 2)
	{
		if (swap->a[i] == min[0] || swap->a[i] == min[1])
			return (1);
		if (swap->a[x] == min[0] || swap->a[x] == min[1])
			return (3);
		x--;
	}
	return (0);
}

int	find_nearest_max(t_swap *swap)
{
	int	i;
	int	x;
	int	max[2];

	i = -1;
	x = swap->asize - 1;
	max[0] = swap->chunk->cmax->min;
	max[1] = swap->chunk->cmax->max;
	while (++i < swap->asize / 2 && x > swap->asize / 2)
	{
		if (swap->a[i] == max[0] || swap->a[i] == max[1])
			return (2);
		if (swap->a[x] == max[0] || swap->a[x] == max[1])
			return (4);
		x--;
	}
	return (0);
}

int	nearest_cmax(t_swap *swap, int m)
{
	int	i;
	int	max[2];

	max[0] = swap->chunk->cmax->min;
	max[1] = swap->chunk->cmax->max;
	i = -1;
	while (++i < swap->asize / 2 && m == 1)
	{
		if (swap->a[i] == max[0])
			return (max[0]);
		else if (swap->a[i] == max[1])
			return (max[1]);
	}
	i = swap->asize;
	while (--i > swap->asize / 2 && m == 2)
	{
		if (swap->a[i] == max[0])
			return (max[0]);
		else if (swap->a[i] == max[1])
			return (max[1]);
	}
	return (0);
}

int	nearest_cmin(t_swap *swap, int m)
{
	int	i;
	int	min[2];

	min[0] = swap->chunk->cmin->min;
	min[1] = swap->chunk->cmin->max;
	i = -1;
	while (++i < swap->asize / 2 && m == 1)
	{
		if (swap->a[i] == min[0])
			return (min[0]);
		else if (swap->a[i] == min[1])
			return (min[1]);
	}
	i = swap->asize;
	while (--i > swap->asize / 2 && m == 2)
	{
		if (swap->a[i] == min[0])
			return (min[0]);
		else if (swap->a[i] == min[1])
			return (min[1]);
	}
	return (0);
}
