/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 08:48:41 by avillar           #+#    #+#             */
/*   Updated: 2022/06/09 11:26:01 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	b_to_a(t_swap *swap)
{
	if (swap->bsize  < 1)
		return ;
	else if (swap->bchunk)
	{
			ft_printf("size = %d\n", swap->bsize);

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
	if (is_sorted(swap->a, swap->asize) == 0)
		return ;
	if (swap->achunk)
	{
		ft_printf("here\n");
		if (is_sorted(swap->a, swap->achunk->size) == 0
			&& is_sorted(swap->a, swap->asize == 1))
		{
			chunk_pb(swap);
		}
		else if (swap->achunk->size <= 2)
			ft_size2a(swap);
		else if (swap->achunk->size > 0)
			move_lessthan2(swap, f_sorta(swap));
		else
		{

			ft_lstdel_first(&swap->achunk);
		}
		a_to_b(swap);
	}
}

void	push_b_toa(t_swap *swap)
{
	while (swap->bsize > 0)
		pa(swap);
}

void	algo1(t_swap *swap)
{
	int	mid;
	int	i;

	i = 0;
	i++;
	i--;
	while (swap->asize > 2)
	{
		mid = fact_sort(swap->a, swap->asize);
		move_lessthan(swap, mid);
		if (swap->asize == 2 && is_sorted(swap->a, swap->asize) == 1)
			sa(swap);
	}
	b_to_a(swap);
	while (is_sorted(swap->a, swap->asize) == 1)
	{
		i++;
		if (swap->asize == 2 && is_sorted(swap->a, swap->asize) == 1)
			sa(swap);
		a_to_b(swap);
		if (swap->asize == 2 && is_sorted(swap->a, swap->asize) == 1)
			sa(swap);
		b_to_a(swap);
		if (i == 6)
		{
			i = 0;
			while (i < swap->asize)
			{
				ft_printf("a -> %d\n", swap->a[i]);
				i++;
			}
		}
	}
	ft_lstclear(&swap->bchunk);
	ft_lstclear(&swap->achunk);







////////////////////////////////////////////////////////////////////////
	i = 0;
	while (i < swap->asize)
	{
		ft_printf("a -> %d\n", swap->a[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_swap	*swap;

	if (argc < 2)
		return (0);
	swap = parse(argv[1]);
	if (parse_check(argv[1]) == 1 || swap == NULL || parse_nodup(swap) == 1)
	{
		write(2, "Error\n", 7);
		if (swap)
			free_swap(swap);
		return (1);
	}
	if (is_sorted(swap->a, swap->asize) == 1)
		algo1(swap);
	free_swap(swap);
	return (0);
}