/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pourcent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:33:00 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 20:33:10 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pourc_endwidth(t_format *format,
												t_handler *handler, char fill)
{
	unsigned int	i;

	i = 0;
	ft_putchar(format->string[format->pos - 1]);
	format->count++;
	while (i < handler->width - 1)
	{
		ft_putchar(fill);
		format->count++;
		i++;
	}
}

static void			pourc_frontwidth(t_format *format,
												t_handler *handler, char fill)
{
	unsigned int	i;

	i = 0;
	if (handler->width)
	{
		while (i < handler->width - 1)
		{
			ft_putchar(fill);
			format->count++;
			i++;
		}
	}
	ft_putchar(format->string[format->pos - 1]);
	format->count++;
}

void				print_pourcent(t_format *format, t_handler *handler)
{
	char			fill;

	if (handler->flags.zero)
		fill = '0';
	else
		fill = ' ';
	if (handler->flags.minus)
	{
		pourc_endwidth(format, handler, fill);
		return ;
	}
	else
		pourc_frontwidth(format, handler, fill);
}
