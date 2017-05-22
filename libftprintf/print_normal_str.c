/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_normal_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:59:50 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 20:00:57 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_putstr_frontwidth(t_format *format,
								t_handler *handler, char *string, char fill)
{
	size_t			length;
	size_t			i;

	if (handler->prec && handler->precision <
			(unsigned int)ft_strlen(string))
		length = handler->precision;
	else
		length = ft_strlen(string);
	i = 0;
	while (i + length < handler->width)
	{
		ft_putchar(fill);
		i++;
		format->count++;
	}
	i = 0;
	while (string[i] != '\0')
	{
		if (handler->prec)
			if (i == handler->precision)
				break ;
		ft_putchar(string[i]);
		i++;
		format->count++;
	}
}

static void			ft_putstr_endwidth(t_format *format,
								t_handler *handler, char *string, char fill)
{
	size_t			i;

	i = 0;
	while (string[i] != '\0')
	{
		if (handler->prec)
			if (i == handler->precision)
				break ;
		ft_putchar(string[i]);
		i++;
		format->count++;
	}
	while (i < handler->width)
	{
		ft_putchar(fill);
		i++;
		format->count++;
	}
}

void				print_normal_str(t_format *format,
												t_handler *handler, char *str)
{
	char			fill;

	if (handler->flags.zero)
		fill = '0';
	else
		fill = ' ';
	if (!str)
	{
		str = ft_strdup("(null)");
		free(str);
	}
	if (handler->flags.minus)
		ft_putstr_endwidth(format, handler, str, fill);
	else
		ft_putstr_frontwidth(format, handler, str, fill);
}
