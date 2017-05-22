/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_lemin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:07:05 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/10 16:08:33 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		double_path(char *tofind, t_paths *p)
{
	while (p)
	{
		if (ft_strcmp(tofind, p->path) == 0)
			return (1);
		p = p->next;
	}
	return (0);
}

static int		check_path(t_paths *p)
{
	while (p)
	{
		if (double_path(p->path, p->next) == 1)
			return (-1);
		p = p->next;
	}
	return (0);
}

t_lemin			*verif_lemin(t_lemin *lemin, t_startend *startend)
{
	if (ft_strcmp(lemin->path->path, startend->start) == 0)
		lemin->status = 1;
	if (check_path(lemin->path) == -1)
		lemin->status = -1;
	return (lemin);
}
