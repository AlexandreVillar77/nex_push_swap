/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:30:52 by avillar           #+#    #+#             */
/*   Updated: 2022/06/09 15:20:18 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	new_chunk(t_swap *swap, int max, int size)
{
	t_chunk	*new;

	new = ft_lstnew(find_min(swap->b, size), max, size);
	if (!new)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	ft_lstadd_front(&swap->bchunk, new);
}

void	ft_printfchunk(t_chunk *chunk)
{
	ft_printf("min: %d, max: %d, size: %d\n", chunk->min, chunk->max, chunk->size);
}

void	ft_lstdel_first(t_chunk **alst)
{
	t_chunk	*tmp;

	if (!alst)
		return ;
	tmp = *alst;
	*alst = (*alst)->next;
	free(tmp);
}

void	ft_printfblst(t_swap *swap)
{
	t_chunk	*tmp;
	int	i;
	int	x;

	i = 0;
	x = 0;
	tmp = swap->bchunk;
	while (tmp)
	{
		ft_printfchunk(tmp);
		x += i;
		i = 0;
		while (i < tmp->size)
		{
			ft_printf("chunk[%d] = %d\n",i , swap->b[i + x]);
			i++;
		}
		ft_printf("c\nc\n");
		tmp = tmp->next;
	}
}

void	ft_printfalst(t_swap *swap)
{
	t_chunk	*tmp;
	int	i;
	int	x;

	i = 0;
	x = 0;
	tmp = swap->achunk;
	while (tmp)
	{
		ft_printfchunk(tmp);
		x += i;
		i = 0;
		while (i < tmp->size)
		{
			ft_printf("chunk[%d] = %d\n",i , swap->a[i + x]);
			i++;
		}
		ft_printf("c\nc\n");
		tmp = tmp->next;
	}
}