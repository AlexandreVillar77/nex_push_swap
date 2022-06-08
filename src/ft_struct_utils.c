/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:30:52 by avillar           #+#    #+#             */
/*   Updated: 2022/06/08 13:07:29 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	new_chunk(t_swap *swap, int max, int size)
{
	t_chunk	*new;

	new = ft_lstnew(find_min(swap->b, size), max, size);
	if (!new)
	{
		perror("Malloc error\n");
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

void	ft_printflst(t_swap *swap)
{
	t_chunk	*tmp;

	tmp = swap->bchunk;
	while (tmp)
	{
		ft_printfchunk(tmp);
		tmp = tmp->next;
	}
}