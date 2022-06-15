/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:08:52 by avillar           #+#    #+#             */
/*   Updated: 2022/06/15 10:03:34 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	algo_manage(t_swap *swap)
{
	if (swap->asize > 5)
		algo1(swap);
	else if (swap->asize <= 3)
		sort_3a(swap);
	else if (swap->asize <= 5)
		sort_5a(swap);
}

void	algo1(t_swap *swap)
{
	int	mid;

	while (swap->asize > 2)
	{
		mid = fact_sort(swap->a, swap->asize);
		move_lessthan(swap, mid);
	}
	if (swap->asize == 2 && swap->a[0] > swap->a[1])
		sa(swap);
	b_to_a(swap);
	while (is_sorted(swap->a, swap->asize) == 1 || swap->bsize > 0)
	{
		a_to_b(swap);
		if (swap->asize == 2 && is_sorted(swap->a, swap->asize) == 1)
			s_to_ss(swap, 0);
		b_to_a(swap);
	}
	ft_lstclear(&swap->bchunk);
	ft_lstclear(&swap->achunk);
}

void	sort_3a(t_swap *swap)
{
	if (swap->asize == 2)
	{
		if (is_sorted(swap->a, swap->asize) == 1)
			sa(swap);
		return ;
	}
	if (is_rev_sorted(swap->a, swap->asize) == 0)
	{
		sa(swap);
		rra(swap);
	}
	if (swap->a[0] > swap->a[1] && swap->a[0] < swap->a[2]
		&& swap->a[1] < swap->a[2])
		sa(swap);
	if (swap->a[0] > swap->a[1] && swap->a[0] > swap->a[2]
		&& swap->a[1] < swap->a[2])
		ra(swap);
	if (swap->a[2] < swap->a[0] && swap->a[1] > swap->a[0])
		rra(swap);
}

int	closest(t_swap *swap, int max)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = -1;
	y = -1;
	while (++i < swap->asize / 2)
	{
		if (swap->a[i] < max)
			break ;
		x++;
	}
	i = swap->asize - 1;
	while (i >= swap->asize / 2)
	{
		if (swap->a[i] < max)
			break ;
		y++;
		i--;
	}
	if (x < y)
		return (0);
	else
		return (1);
}

void	sort_5a(t_swap *swap)
{
	int	max;

	max = fact_sort(swap->a, swap->asize);
	while (swap->asize > 3)
	{
		while (swap->a[0] >= max)
		{
			if (closest(swap, max) == 0)
				ra(swap);
			else
				rra(swap);
		}
		pb(swap);
	}
	sort_3a(swap);
	if (is_rev_sorted(swap->b, swap->bsize) == 1)
		sb(swap);
	while (swap->bsize > 0)
		pa(swap);
}
