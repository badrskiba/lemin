/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:21:24 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/10 20:20:37 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	t_lemin		*cpy_lem(t_lemin *lemin, t_paths *p)
{
	t_lemin			*tmp;

	if (!(tmp = (t_lemin*)malloc(sizeof(*tmp))))
		return (NULL);
	tmp->status = 0;
	tmp->path = p;
	tmp->next = lemin->next;
	lemin->next = tmp;
	return (lemin);
}

static	t_lemin		*fill_lemin_next(t_lemin *lemin, t_links *links,
		t_paths *path, t_startend *startend)
{
	while (links)
	{
		if ((ft_strcmp(links->name[0], path->path) == 0) ||
				(ft_strcmp(links->name[1], path->path) == 0))
		{
			lemin = cpy_lem(lemin, path);
			lemin->next->path = new_path(links->name, lemin->path);
			verif_lemin(lemin->next, startend);
		}
		links = links->next;
	}
	return (lemin);
}

t_lemin				*fill_lemin(t_lemin *lemin,
		t_links *links, t_startend *startend)
{
	t_lemin			*test;
	int				i;

	test = lemin;
	i = 0;
	while (test)
	{
		if (test->status == 0)
		{
			test->status = -1;
			test = fill_lemin_next(test, links, test->path, startend);
			if (i == 10000)
				break ;
			i++;
		}
		test = test->next;
	}
	return (lemin);
}
