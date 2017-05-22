/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:08:47 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/10 16:09:25 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			check_room(char *str, t_room *room)
{
	while (room)
	{
		if (ft_strcmp(str, room->name) == 0)
			return (1);
		room = room->next;
	}
	return (-1);
}

int					verif_links(t_links *links, t_room *room)
{
	while (links)
	{
		if (check_room(links->name[0], room) == -1 ||
				check_room(links->name[1], room) == -1)
			return (-1);
		links = links->next;
	}
	return (0);
}
