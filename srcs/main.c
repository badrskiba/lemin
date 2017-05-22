/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:22:54 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/10 15:24:59 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		print_code(t_code *c)
{
	if (c)
	{
		print_code(c->next);
		ft_printf("%s\n", c->line);
	}
}

int				main(void)
{
	t_code		*code;
	t_room		*room;
	t_links		*links;
	t_lemin		*lemin;
	int			ants;

	ants = 0;
	if ((code = get_code(NULL)) == NULL)
		return (ft_printf("erreur code"));
	if ((ants = get_ants(code)) == 0)
		return (ft_printf("erreur number of ants"));
	if ((room = get_room(NULL, code)) == NULL)
		return (ft_printf("erreur in rooms"));
	if ((links = get_links(NULL, code)) == NULL)
		return (ft_printf("erreur in links"));
	if (verif_links(links, room) == -1)
		return (ft_printf("erreur in links"));
	if ((lemin = get_lemin(ants, NULL, room, links)) == NULL)
		return (ft_printf("there is no lemin for this map"));
	lemin = min_path(lemin);
	print_code(code);
	ft_printf("\n");
	print_lemin(lemin, ants);
	return (0);
}
