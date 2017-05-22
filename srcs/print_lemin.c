/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lemin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:43:31 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/10 16:06:14 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	t_lemin		*ft_move(t_lemin *lemin, int ants, int max_ants)
{
	if (ants <= max_ants)
		lemin->path->ants = ants;
	lemin = ft_goto_lastantz(lemin, max_ants);
	return (lemin);
}

static	int			ft_check_end(t_lemin *lemin, int max_ants)
{
	t_lemin			*tmp;

	if (!(tmp = malloc(sizeof(t_lemin))))
		return (1);
	tmp->path = lemin->path;
	while (lemin->path->next)
		lemin->path = lemin->path->next;
	if (tmp->path->ants == max_ants)
	{
		lemin->path = tmp->path;
		return (1);
	}
	lemin->path = tmp->path;
	return (0);
}

static	int			ft_check_end_next(t_lemin *lemin, int max_ants)
{
	int				i;
	t_lemin			*tmp;

	if (!(tmp = malloc(sizeof(t_lemin))))
		return (1);
	tmp->path = lemin->path;
	i = 0;
	while (lemin->path->next)
	{
		i++;
		lemin->path = lemin->path->next;
	}
	if (lemin->path->ants == max_ants)
	{
		lemin->path = tmp->path;
		return (1);
	}
	lemin->path = tmp->path;
	return (0);
}

void				print_lemin(t_lemin *lemin, int max_ants)
{
	int				ants;
	int				i;

	ants = 1;
	i = 1;
	while (!ft_check_end(lemin, max_ants))
	{
		lemin = ft_move(lemin, ants, max_ants);
		ft_affich_round(lemin);
		ants++;
	}
	while (!ft_check_end_next(lemin, max_ants))
	{
		lemin = ft_move(lemin, ants, max_ants);
		ft_affich_round_fin(lemin, max_ants);
		if (!ft_check_end_next(lemin, max_ants))
			ft_printf("\n");
	}
}
