/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_chunk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:08:40 by avillar           #+#    #+#             */
/*   Updated: 2022/06/14 16:21:45 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	new_achunk(t_swap *swap, int max, int size)
{
	t_chunk	*new;

	new = ft_lstnew(find_min(swap->a, size), max, size);
	if (!new)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	ft_lstadd_front(&swap->achunk, new);
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

void	move_lessthan2(t_swap *swap, int mid)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (ft_hereis(swap->a, mid, swap->achunk->size) == 0
		&& swap->asize > 0)
	{
		if (swap->a[0] < mid)
		{
			x++;
			pb(swap);
			swap->achunk->size--;
		}
		else
		{
			i++;
			ra(swap);
		}
	}
	while (i-- > 0 && swap->asize > swap->achunk->size
		&& swap->achunk->size > 0)
		rra(swap);
	ft_update_chunk(swap->a, swap->achunk);
	new_chunk(swap, find_max(swap->b, x), x);
}

void	ft_size2a(t_swap *swap)
{
	int	x;

	x = swap->achunk->size;
	if (swap->achunk->size == 1)
		pb(swap);
	else
	{
		if (swap->a[0] > swap->a[1])
			sa(swap);
		pb(swap);
		pb(swap);
	}
	new_chunk(swap, find_max(swap->b, x), x);
	ft_lstdel_first(&swap->achunk);
}

void	chunk_pb(t_swap *swap)
{
	int	x;

	x = swap->achunk->size;
	while (swap->achunk->size > 0)
	{
		pb(swap);
		swap->achunk->size--;
	}
	new_chunk(swap, find_max(swap->b, x), x);
	ft_lstdel_first(&swap->achunk);
}
