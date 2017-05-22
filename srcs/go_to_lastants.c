/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_lastants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:34:22 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/10 14:34:43 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lemin			*ft_goto_lastantz(t_lemin *lemin, int max_ants)
{
	t_lemin		*tmp;
	int			a;

	if (!(tmp = malloc(sizeof(t_lemin))))
		return (NULL);
	tmp->path = lemin->path;
	a = 0;
	while (lemin->path->next)
	{
		if (lemin->path->ants - 1 > lemin->path->next->ants && a == 0)
			lemin->path->next->ants++;
		else if (lemin->path->ants == max_ants || a == 1)
		{
			a = 1;
			lemin->path->next->ants++;
		}
		lemin->path = lemin->path->next;
	}
	lemin->path = tmp->path;
	return (lemin);
}
