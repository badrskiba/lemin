/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:32:04 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/10 14:33:03 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	t_room	*new_room(t_room *new_room,
										t_room *nextroom, t_code *code)
{
	if (!(new_room = malloc(sizeof(*nextroom))))
		return (NULL);
	new_room->next = nextroom;
	new_room->status = 1;
	new_room->name = ft_strsub(code->line, 0, ft_strlen_chr(code->line, ' '));
	return (new_room);
}

t_room			*get_room(t_room *room, t_code *code)
{
	int		i;

	i = 0;
	while (code)
	{
		if (code->status == 4)
			if ((room = new_room(NULL, room, code)) == NULL)
				return (NULL);
		if (code->status == 2)
			room->status = 0;
		if (code->status == 3)
			room->status = 2;
		code = code->next;
	}
	return (room);
}
