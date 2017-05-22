/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:29:55 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/10 14:30:07 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_links		*new_links(t_links *new_links,
											t_links *next_links, t_code *code)
{
	if (!(new_links = malloc(sizeof(*new_links))))
		return (NULL);
	new_links->name = ft_strsplit(code->line, '-');
	new_links->next = next_links;
	return (new_links);
}

t_links				*get_links(t_links *links, t_code *code)
{
	int i;

	i = 0;
	while (code)
	{
		if (code->status == 5)
			if (!(links = new_links(NULL, links, code)))
				return (NULL);
		code = code->next;
	}
	return (links);
}
