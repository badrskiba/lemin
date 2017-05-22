/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:54:20 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 16:04:20 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cheek_flags_next(char a, t_handler *handler)
{
	if (a == '0')
	{
		if (!handler->flags.minus)
		{
			handler->flags.zero = 1;
			return (1);
		}
	}
	else if (a == '#')
	{
		handler->flags.hashtag = 1;
		return (1);
	}
	return (0);
}

int		cheek_flags(char a, t_handler *handler)
{
	if (a == '+')
	{
		handler->flags.plus = 1;
		handler->flags.space = 0;
		return (1);
	}
	else if (a == ' ')
	{
		if (!handler->flags.plus)
			handler->flags.space = 1;
		return (1);
	}
	else if (a == '-')
	{
		handler->flags.minus = 1;
		handler->flags.zero = 0;
		return (1);
	}
	return (cheek_flags_next(a, handler));
}

void	handle_flags(t_format *format, t_handler *handler)
{
	while (cheek_flags(format->string[format->pos], handler))
		format->pos++;
}
