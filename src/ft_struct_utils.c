/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:30:52 by avillar           #+#    #+#             */
/*   Updated: 2022/06/15 10:04:43 by avillar          ###   ########.fr       */
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

void	ft_lstdel_first(t_chunk **alst)
{
	t_chunk	*tmp;

	if (!alst)
		return ;
	tmp = *alst;
	*alst = (*alst)->next;
	free(tmp);
}
