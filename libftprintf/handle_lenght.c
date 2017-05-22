/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lenght.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:04:38 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 16:19:35 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void		handle_length_next_1(t_format *format, t_handler *handler)
{
	if (format->string[format->pos] == 'j')
	{
		handler->lenght = j;
		format->pos++;
		return ;
	}
	else if (format->string[format->pos] == 'z')
	{
		handler->lenght = z;
		format->pos++;
		return ;
	}
	if (!format->string[format->pos])
		handler->lenght = Default;
}

static	void		handle_length_next(t_format *format, t_handler *handler)
{
	if (format->string[format->pos] == 'l')
	{
		if (format->string[format->pos + 1] == 'l')
		{
			handler->lenght = ll;
			format->pos += 2;
			return ;
		}
		else
		{
			handler->lenght = l;
			format->pos++;
			return ;
		}
	}
	handle_length_next_1(format, handler);
}

void				handle_length(t_format *format, t_handler *handler)
{
	if (format->string[format->pos] == 'h')
	{
		if (format->string[format->pos + 1] == 'h')
		{
			handler->lenght = hh;
			format->pos += 2;
			return ;
		}
		else
		{
			handler->lenght = h;
			format->pos++;
			return ;
		}
	}
	handle_length_next(format, handler);
}
