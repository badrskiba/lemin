/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:50:24 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 19:37:16 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			put_precision_hex(char *string, t_format *format,
														t_handler *handler)
{
	int		a;

	if ((unsigned int)ft_strlen(string) < handler->precision)
	{
		a = ft_strlen(string);
		while ((unsigned int)a < handler->precision)
		{
			ft_putchar('0');
			a++;
			format->count++;
		}
	}
}

int				zero_x_print(t_format *format, t_handler *handler)
{
	ft_putchar('0');
	format->count++;
	if (handler->type == hex_lower || handler->type == pointer)
	{
		ft_putchar('x');
		format->count++;
		return (2);
	}
	else
	{
		ft_putchar('X');
		format->count++;
		return (2);
	}
	return (1);
}

static void		print_hex_next(t_format *format,
											t_handler *handler, uintmax_t n)
{
	char *string;

	string = NULL;
	if (handler->type == hex_upper)
		string = (printf_strupper(printf_itoa_base(n, 16)));
	if (handler->type == hex_lower || handler->type == pointer)
		string = (printf_strlower(printf_itoa_base(n, 16)));
	if (handler->flags.minus)
		print_hex_endwidth(string, format, handler, ' ');
	else
		print_hex_frontwidth(string, format, handler, '0');
	free(string);
}

void			print_hex(t_format *format, t_handler *handler, va_list arg)
{
	uintmax_t	n;

	if (handler->lenght == z)
		n = (uintmax_t)va_arg(arg, size_t);
	else if (handler->lenght == j)
		n = va_arg(arg, uintmax_t);
	else if (handler->lenght == ll)
		n = (uintmax_t)va_arg(arg, unsigned long long);
	else if (handler->lenght == l)
		n = (uintmax_t)va_arg(arg, unsigned long);
	else if (handler->lenght == h)
		n = (uintmax_t)(unsigned short)va_arg(arg, unsigned int);
	else if (handler->lenght == hh)
		n = (uintmax_t)(unsigned char)va_arg(arg, unsigned int);
	else
		n = (uintmax_t)va_arg(arg, unsigned int);
	print_hex_next(format, handler, n);
}
