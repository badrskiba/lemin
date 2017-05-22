/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:25:12 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/10 16:38:14 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				lst_count_path(t_paths *path)
{
	int			i;

	i = 0;
	while (path)
	{
		i++;
		path = path->next;
	}
	return (i);
}

t_lemin			*min_path(t_lemin *lemin)
{
	t_lemin		*tmp;
	t_lemin		*tmp1;

	tmp = lemin;
	if (!(tmp1 = malloc(sizeof(*lemin))))
		return (NULL);
	while (tmp->next)
	{
		if (tmp->status == 1)
		{
			tmp1->path = tmp->path;
			break ;
		}
		tmp = tmp->next;
	}
	while (tmp->next)
	{
		if (tmp->status == 1)
			if ((lst_count_path(tmp->path) <= lst_count_path(tmp1->path)))
				tmp1->path = tmp->path;
		tmp = tmp->next;
	}
	lemin = tmp1;
	return (lemin);
}
