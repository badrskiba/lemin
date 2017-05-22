/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:44:38 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 18:44:54 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char_next(char c, t_format *format, t_handler *handler)
{
	ft_putchar(c);
	format->count++;
	ft_putchar('\0');
	while (handler->width > 1)
	{
		if (handler->flags.zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		format->count++;
		handler->width--;
	}
	return ;
}

void	print_char(char c, t_format *format, t_handler *handler)
{
	if (handler->width && !handler->flags.minus)
	{
		while (handler->width > 1)
		{
			if (handler->flags.zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			format->count++;
			handler->width--;
		}
		ft_putchar(c);
		format->count++;
		ft_putchar('\0');
		return ;
	}
	else if (handler->width && handler->flags.minus)
	{
		print_char_next(c, format, handler);
		return ;
	}
	ft_putchar(c);
	format->count++;
}

void	print_chr(t_format *format, t_handler *handler, va_list arg)
{
	if (handler->lenght == l)
		print_wint(va_arg(arg, wint_t), format);
	else
		print_char(va_arg(arg, int), format, handler);
}
