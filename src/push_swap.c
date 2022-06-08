/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 08:48:41 by avillar           #+#    #+#             */
/*   Updated: 2022/06/08 16:24:52 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	b_to_a(t_swap *swap)
{
	if (swap->bchunk)
	{
		if (is_rev_sorted(swap->b, swap->bchunk->size) == 0)
			chunk_pa(swap);
		else if (swap->bchunk->size <= 2)
			ft_size2(swap);
		else
		{
			move_morethan(swap, catchmid(f_sortb(swap), swap->bchunk->size));
		}
		b_to_a(swap);
	}
}

void	a_to_b(t_swap *swap)
{
	if (is_sorted(swap->a, swap->asize) == 0)
		return ;
	if (swap->achunk)
	{
		if (is_sorted(swap->a, swap->achunk->size) == 0
			&& is_sorted(swap->a, swap->asize == 1))
			chunk_pb(swap);
		else if (swap->achunk->size <= 2)
			ft_size2a(swap);
		else if (swap->achunk->size > 0)
		{
			move_lessthan2(swap, catchmid(f_sorta(swap), swap->achunk->size));
		}
		else
			ft_lstdel_first(&swap->achunk);
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
		mid = catchmid(fact_sort(swap->a, swap->asize), swap->asize);
		
		move_lessthan(swap, mid);
		if (swap->asize == 2 && is_sorted(swap->a, swap->asize) == 1)
			sa(swap);
	}
	b_to_a(swap);
	while (is_sorted(swap->a, swap->asize) == 1)
	{
		i++;
		//if (swap->asize == 2 && is_sorted(swap->a, swap->asize) == 1)
		//	sa(swap);
		a_to_b(swap);
		//ft_printf("here\n");
		b_to_a(swap);


		if (i == 2)
		{
			ft_printf("i = %d\n", i);
			i = 0;
			while (i < swap->asize)
			{
				ft_printf("a -> %d\n", swap->a[i]);
				i++;
			}
			i = 0;
			ft_printf("\n\n\n");
			while (i < swap->bsize)
			{
				ft_printf("b -> %d\n", swap->b[i]);
				i++;
			}
			i = 10;
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
		return (1);
	swap = parse(argv[1]);
	if (parse_check(argv[1]) == 1 || parse_nodup(swap) == 1)
		return (1);
	if (is_sorted(swap->a, swap->asize) == 0)
		return (0);
	algo1(swap);
	free(swap->b);
	free(swap->a);
	free(swap);
	return (0);
}