/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:13:43 by avillar           #+#    #+#             */
/*   Updated: 2022/06/15 10:17:26 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	init_swap(t_swap *swap, int *a, int size)
{
	swap->a = a;
	swap->b = NULL;
	swap->bsize = 0;
	swap->asize = size;
	swap->aini_size = size;
	swap->bini_size = swap->aini_size / 2;
	swap->bchunk = NULL;
	swap->achunk = NULL;
}

t_swap	*parse(char *str)
{
	int		*res;
	int		i;
	char	**tab;
	t_swap	*swap;

	i = 0;
	tab = ft_split(str, ' ');
	res = malloc(sizeof(int) * (ft_tablen(tab)));
	swap = malloc(sizeof(t_swap));
	if (!res || !swap)
		return (NULL);
	if (check_max(tab) == 1)
		return (NULL);
	while (tab[i])
	{
		res[i] = ft_atoi(tab[i]);
		i++;
	}
	init_swap(swap, res, ft_tablen(tab));
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (swap);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	init_split(t_split *split, const char *s, char c)
{
	split->i = skipc(s, c, 0);
	split->j = 0;
	split->len = 0;
}

long int	ft_atoi(const char *str)
{
	long int		rtn;
	int				nb;

	rtn = 0;
	nb = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		nb = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		rtn *= 10;
		rtn += *str - 48;
		str++;
	}
	rtn = rtn * nb;
	return (rtn);
}
