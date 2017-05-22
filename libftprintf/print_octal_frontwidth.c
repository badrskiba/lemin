/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal_frontwidth.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:27:11 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 20:27:35 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_octal_frontnext(char *string, t_format *format,
														t_handler *handler)
{
	size_t		i;

	i = 0;
	while (string[i] != '\0')
	{
		if (handler->prec && string[0] == '0' && handler->width)
		{
			ft_putchar(' ');
			format->count++;
		}
		else if (handler->prec && string[0] == '0' && !handler->flags.hashtag)
			;
		else
		{
			ft_putchar(string[i]);
			format->count++;
		}
		i++;
	}
}

void			print_octal_frontwidth(char *string, t_format *format,
												t_handler *handler, char fill)
{
	size_t		length;
	size_t		a;

	a = 0;
	length = ((unsigned int)ft_strlen(string) < handler->precision) ?
		handler->precision : (unsigned int)ft_strlen(string);
	if (handler->precision || !handler->flags.zero)
		fill = ' ';
	if (fill == ' ')
	{
		if (handler->flags.hashtag)
			put_width(format, handler, fill, length + 1);
		else
			put_width(format, handler, fill, length);
	}
	if (string[0] != '\0')
		if (handler->flags.hashtag && string[0] != '0')
			a = zero_print(format);
	if (fill == '0')
		put_width(format, handler, fill, length + a);
	if (string[0] != '\0')
		if (handler->precision)
			put_precision_octal(string, format, handler, a);
	print_octal_frontnext(string, format, handler);
}
