/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:19:50 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 16:43:02 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_precision(t_format *format, t_handler *handler)
{
	unsigned int i;

	i = 0;
	if (format->string[format->pos] == '.')
	{
		handler->prec = 1;
		format->pos++;
		while (format->string[format->pos] >= '0' &&
				format->string[format->pos] <= '9')
		{
			i = i * 10 + (format->string[format->pos] - '0');
			format->pos++;
		}
		handler->precision = i;
	}
	else
		handler->precision = i;
}
