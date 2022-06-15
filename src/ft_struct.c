/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:01:06 by avillar           #+#    #+#             */
/*   Updated: 2022/06/15 10:04:58 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

t_chunk	*ft_lstnew(int min, int max, int size)
{
	t_chunk	*new;

	new = malloc(sizeof(t_chunk));
	if (!new)
		return (0);
	new->min = min;
	new->max = max;
	new->size = size;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_chunk **alst, t_chunk *new)
{
	if (!new || !alst)
		return ;
	new->next = *alst;
	*alst = new;
}

t_chunk	*ft_lstlast(t_chunk *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_chunk **alst, t_chunk *new)
{
	t_chunk	*cons;

	if (new == 0)
		return ;
	if (*alst == 0)
		*alst = new;
	else
	{
		cons = ft_lstlast(*alst);
		cons->next = new;
	}
}

void	ft_lstclear(t_chunk **lst)
{
	t_chunk	*cons;
	t_chunk	*todel;

	if (lst == 0)
		return ;
	cons = *lst;
	while (cons)
	{
		todel = cons->next;
		free(cons);
		cons = todel;
	}
	*lst = 0;
}
