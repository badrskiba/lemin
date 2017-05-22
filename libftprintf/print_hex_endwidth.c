/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_endwidth.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:28:37 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/12 16:38:03 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	affiche(char *string, t_format *format, size_t i)
{
	while (string[i] != '\0')
	{
		ft_putchar(string[i++]);
		format->count++;
	}
	return (i);
}

void			print_hex_endwidth(char *string, t_format *format,
		t_handler *handler, char fill)
{
	size_t		i;
	size_t		a;

	i = 0;
	a = 0;
	if (handler->flags.zero)
		fill = '0';
	if (string[i] != '\0')
	{
		if ((handler->flags.hashtag && string[i] != '0')
				|| handler->type == pointer)
			a = zero_x_print(format, handler);
		if (handler->precision)
			put_precision_hex(string, format, handler);
	}
	i = affiche(string, format, i);
	while (i < handler->width - a && handler->width >= a)
	{
		ft_putchar(fill);
		i++;
		format->count++;
	}
}
