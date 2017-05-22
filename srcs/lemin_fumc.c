/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_fumc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:21:18 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/10 15:22:44 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		strisdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 48 && s[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

int		chariter(char *s, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			a++;
		i++;
	}
	return (a);
}

int		ft_strlen_chr(char *s, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = s;
	while (tmp[i] != c)
	{
		i++;
	}
	return (i);
}

int		get_ants(t_code *code)
{
	int	i;

	i = 0;
	while (code)
	{
		if (code->status == 1)
			i = ft_atoi(code->line);
		code = code->next;
	}
	return (i);
}

int		count_links(t_links *links, char *matchwith)
{
	int	i;

	i = 0;
	while (links)
	{
		if (ft_strcmp(matchwith, links->name[0]) == 0
				|| ft_strcmp(matchwith, links->name[1]) == 0)
			i++;
		links = links->next;
	}
	return (i);
}
