/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lemin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:39:48 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/10 20:21:25 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_paths				*new_path(char **names, t_paths *next_paths)
{
	char			*name;
	t_paths			*new;

	if (strcmp(names[0], next_paths->path) == 0)
		name = names[1];
	else
		name = names[0];
	if (!(new = malloc(sizeof(t_paths))))
		return (NULL);
	new->next = next_paths;
	new->path = name;
	return (new);
}

static t_lemin		*init_lemin(t_lemin *next, t_startend *startend)
{
	t_lemin			*new;

	if (!(new = malloc(sizeof(t_lemin))))
		return (NULL);
	new->next = next;
	new->status = 0;
	if (!(new->path = malloc(sizeof(t_paths))))
		return (NULL);
	new->path->next = NULL;
	new->path->path = ft_strdup(startend->end);
	return (new);
}

static t_lemin		*create_lemin(t_lemin *lemin, t_links *links,
														t_startend *startend)
{
	t_lemin			*new_lemin;
	t_lemin			*tmp;

	new_lemin = NULL;
	while (links)
	{
		if (((ft_strcmp(startend->end, links->name[0]) == 0)) ||
				((ft_strcmp(startend->end, links->name[1]) == 0)))
		{
			if (!(new_lemin = init_lemin(new_lemin, startend)))
				return (NULL);
			if (!(new_lemin->path = new_path(links->name, new_lemin->path)))
				return (NULL);
			if ((ft_strcmp(links->name[0], startend->start) == 0) || (
				(ft_strcmp(startend->start, links->name[1]) == 0)))
				new_lemin->status = 1;
		}
		links = links->next;
	}
	tmp = new_lemin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = lemin;
	return (new_lemin);
}

t_lemin				*new_lemin(t_lemin *lemin, t_links *links,
														t_startend *startend)
{
	if (lemin)
	{
		if (!(lemin = fill_lemin(lemin, links, startend)))
			return (NULL);
	}
	if (!(lemin = create_lemin(lemin, links, startend)))
		return (NULL);
	return (lemin);
}
