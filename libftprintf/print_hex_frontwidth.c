/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_frontwidth.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:11:28 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 19:13:16 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_hex_frontnext(char *string, t_format *format,
		t_handler *handler, size_t i)
{
	if (string[i] != '\0')
		if (handler->precision)
			put_precision_hex(string, format, handler);
	while (string[i] != '\0')
	{
		if (handler->prec && string[0] == '0' &&
				!handler->width && handler->precision == 0)
			;
		else if (handler->prec && string[0] == '0' && handler->type != pointer)
		{
			ft_putchar(' ');
			format->count++;
		}
		else
		{
			ft_putchar(string[i]);
			format->count++;
		}
		i++;
	}
}

void			print_hex_frontwidth(char *string, t_format *format,
		t_handler *handler, char fill)
{
	size_t		length;
	size_t		i;
	size_t		a;

	i = 0;
	a = 0;
	length = ((unsigned int)ft_strlen(string) < handler->precision) ?
		handler->precision : (unsigned int)ft_strlen(string);
	if (handler->precision || !handler->flags.zero)
		fill = ' ';
	if (fill == ' ')
	{
		if (handler->flags.hashtag)
			put_width(format, handler, fill, length + 2);
		else
			put_width(format, handler, fill, length);
	}
	if (string[i] != '\0')
		if ((handler->flags.hashtag && string[i] != '0')
				|| handler->type == pointer)
			a = zero_x_print(format, handler);
	if (fill == '0')
		put_width(format, handler, fill, length + a);
	print_hex_frontnext(string, format, handler, i);
}
