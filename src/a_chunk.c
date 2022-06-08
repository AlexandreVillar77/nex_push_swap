/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_chunk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:08:40 by avillar           #+#    #+#             */
/*   Updated: 2022/06/08 14:15:27 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	new_achunk(t_swap *swap, int max, int size)
{
	t_chunk	*new;

	new = ft_lstnew(find_min(swap->a, size), max, size);
	if (!new)
	{
		perror("Malloc error\n");
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
		ft_printf("mid: %d\n", mid);
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
		else
			ra(swap);
		/*else if (find_nearest(swap, mid) == 0)
			ra(swap);
		else
			rra(swap);
		x = 0;
			while (x < swap->asize)
			{
				ft_printf("a -> %d\n", swap->a[x]);
				x++;
			}*/
	}
	new_chunk(swap, find_max(swap->b, i), i);
}

void	move_lessthan2(t_swap *swap, int mid)
{
	int	i;
	int	x;

	i = 0;
	while (ft_hereis(swap->a, mid, swap->achunk->size) == 0)
	{
		if (swap->a[0] < mid)
		{
			x++;
			pa(swap);
			swap->achunk->size--;
			while (i > 0)
			{
				i--;
				rra(swap);
			}
		}
		else
		{
			i++;
			ra(swap);
		}
	}
	/*ft_printf("mid: %d\n", mid);
	ft_printf("size = %d\n", swap->achunk->size);
	static int	y = 0;
	while (y < swap->achunk->size)
	{
		ft_printf("a -> %d\n", swap->a[y]);
		y++;
	}*/
	new_chunk(swap, find_max(swap->b, x), x);
}

void	ft_size2a(t_swap *swap)
{
	if (swap->achunk->size == 1)
		pb(swap);
	else
	{
		if (swap->a[0] > swap->a[1])
			sa(swap);
		pb(swap);
		pb(swap);
	}
	ft_lstdel_first(&swap->achunk);
}

void	chunk_pb(t_swap *swap)
{
	while (swap->achunk->size > 0)
	{
		pb(swap);
		swap->achunk->size--;
	}
	ft_lstdel_first(&swap->achunk);
}