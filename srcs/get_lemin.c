/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lemin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:11:19 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/10 18:06:39 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_startend	*get_startend(t_room *room, t_startend *startend)
{
	if (!(startend = (t_startend*)malloc(sizeof(*startend))))
		return (NULL);
	while (room)
	{
		if (room->status == 0)
			startend->start = ft_strdup(room->name);
		if (room->status == 2)
			startend->end = ft_strdup(room->name);
		room = room->next;
	}
	return (startend);
}

static int			check_lemin(t_lemin *lemin, int ants)
{
	int				a;
	static int		counter = 0;

	a = 0;
	counter++;
	if (counter == 1)
		return (0);
	while (lemin)
	{
		if (lemin->status == 1)
			a++;
		lemin = lemin->next;
	}
	if (a >= ants - 1 || (counter >= 1000 && a))
		return (1);
	else if (counter >= 1000 && !a)
		return (-1);
	return (0);
}

t_lemin				*get_lemin(int ants, t_lemin *lemin, t_room *room,
															t_links *links)
{
	t_startend		*startend;
	t_lemin			*tmp;
	int				i;
	int				a;

	if (!(tmp = malloc(sizeof(t_lemin))))
		return (NULL);
	i = 0;
	a = 0;
	if (!(startend = get_startend(room, NULL)))
		return (NULL);
	if (count_links(links, startend->start) == 0
			|| count_links(links, startend->end) == 0)
		return (NULL);
	while (check_lemin(lemin, ants) == 0)
	{
		if (check_lemin(lemin, ants) == -1)
			return (NULL);
		lemin = new_lemin(lemin, links, startend);
	}
	return (lemin);
}
