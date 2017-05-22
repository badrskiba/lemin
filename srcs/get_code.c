/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:28:36 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/22 15:42:02 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	int		check_code(t_code *code)
{
	int			a;
	int			b;
	int			c;

	a = 0;
	b = 0;
	c = 0;
	while (code)
	{
		if (code->status == 4)
			b++;
		if (code->status == 5)
			c++;
		if (code->status == 1 || code->status == 2 || code->status == 3)
			a++;
		code = code->next;
	}
	if (a != 3 || b == 0 || c == 0)
		return (0);
	return (1);
}

static	int		get_status(char *str)
{
	if (strisdigit(str) == 1)
		return (1);
	else if (ft_strcmp(str, "##start") == 0)
		return (2);
	else if (ft_strcmp(str, "##end") == 0)
		return (3);
	else if ((chariter(str, ' ') == 2 && str[0] != '#') &&
			(chariter(str, ' ') == 2 && str[0] != 'L'))
		return (4);
	else if (chariter(str, '-') == 1 && str[0] != '#')
		return (5);
	else if ((chariter(str, ' ') == 0 && str[0] != '#') &&
			(chariter(str, ' ') == 0 && str[0] != 'L'))
		return (4);
	else if (str[0] == '#' && str[1] != '#')
		return (6);
	return (0);
}

static t_code	*new_code_line(t_code *code, char *str, t_code *next)
{
	if (!(code = malloc(sizeof(*code))))
		return (NULL);
	code->line = ft_strdup(str);
	if ((code->status = get_status(str)) == 0)
		return (NULL);
	code->next = next;
	return (code);
}

t_code			*get_code(t_code *code)
{
	char		*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if ((code = new_code_line(NULL, line, code)) == NULL)
			return (NULL);
		line = NULL;
	}
	if (check_code(code) == 0)
		return (NULL);
	return (code);
}
