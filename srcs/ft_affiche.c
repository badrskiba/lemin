/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affiche.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:23:44 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/10 16:05:40 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_affich_round(t_lemin *lemin)
{
	t_lemin	*tmp;

	if (!(tmp = malloc(sizeof(t_lemin))))
		return ;
	tmp->path = lemin->path;
	while (lemin->path->next)
	{
		if (lemin->path->ants != 0)
			ft_printf("L%d-%s", lemin->path->ants, lemin->path->next->path);
		lemin->path = lemin->path->next;
	}
	ft_printf("\n");
	lemin->path = tmp->path;
}

void		ft_affich_round_fin(t_lemin *lemin, int max_ants)
{
	t_lemin	*tmp;

	if (!(tmp = malloc(sizeof(t_lemin))))
		return ;
	tmp->path = lemin->path;
	lemin->path = lemin->path->next;
	while (lemin->path->next)
	{
		if (lemin->path->ants <= max_ants)
			ft_printf("L%d-%s", lemin->path->ants, lemin->path->next->path);
		lemin->path = lemin->path->next;
	}
	lemin->path = tmp->path;
}
