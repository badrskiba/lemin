/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:42:04 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 19:42:27 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_signed_int_next(t_format *format, t_handler *handler, intmax_t n)
{
	int nbn;

	nbn = 0;
	if (handler->flags.minus)
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = n * -1;
			format->count++;
			handler->flags.plus = 0;
			handler->n = 1;
		}
		print_int_endwidth(format, handler, n, 0);
	}
	else if (!handler->flags.minus)
	{
		if (n < 0)
		{
			n = n * -1;
			format->count++;
			nbn = 1;
		}
		print_int_frontwidth(format, handler, n, nbn);
	}
}

void	print_signed_int(t_format *format, t_handler *handler, va_list arg)
{
	intmax_t n;

	n = 0;
	if (handler->lenght == hh)
		n = (signed char)va_arg(arg, int);
	else if (handler->lenght == h)
	{
		n = va_arg(arg, int);
		if (n == 32768)
			n = -n;
	}
	else if (handler->lenght == l)
		n = va_arg(arg, long);
	else if (handler->lenght == ll)
		n = va_arg(arg, long long int);
	else if (handler->lenght == z)
		n = va_arg(arg, size_t);
	else if (handler->lenght == j)
		n = va_arg(arg, intmax_t);
	else
		n = va_arg(arg, int);
	print_signed_int_next(format, handler, n);
}

void	print_unsigned_int(t_format *format, t_handler *handler, va_list arg)
{
	uintmax_t n;

	n = 0;
	if (handler->lenght == hh)
		n = (unsigned char)va_arg(arg, int);
	else if (handler->lenght == h)
		n = (unsigned int)va_arg(arg, int);
	else if (handler->lenght == l)
		n = va_arg(arg, unsigned long);
	else if (handler->lenght == ll)
		n = va_arg(arg, unsigned long long int);
	else if (handler->lenght == z)
		n = va_arg(arg, size_t);
	else if (handler->lenght == j)
		n = va_arg(arg, intmax_t);
	else
		n = va_arg(arg, unsigned int);
	if (handler->flags.minus)
		print_uint_endwidth(format, handler, n);
	else if (!handler->flags.minus)
		print_uint_frontwidth(format, handler, n, 0);
}

void	print_int(t_format *format, t_handler *handler, va_list arg)
{
	if (handler->type == s_deci)
		print_signed_int(format, handler, arg);
	else if (handler->type == us_deci)
		print_unsigned_int(format, handler, arg);
}
