/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:12:37 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 20:29:09 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					put_precision_octal(char *string, t_format *format,
													t_handler *handler, int i)
{
	int				a;
	int				b;

	a = 0;
	b = 0;
	if ((unsigned int)ft_strlen(string) < handler->precision)
	{
		if (handler->flags.hashtag)
			a = ft_strlen(string) + i;
		else
			a = ft_strlen(string);
		while ((unsigned int)a < handler->precision)
		{
			ft_putchar('0');
			a++;
			b++;
			format->count++;
		}
	}
	return (b);
}

int					zero_print(t_format *format)
{
	ft_putchar('0');
	format->count++;
	return (1);
}

static void			print_octal_endwidth(char *string, t_format *format,
														t_handler *handler)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	b;

	i = 0;
	a = 0;
	b = 0;
	if (string[i] != '\0')
	{
		if (handler->flags.hashtag && string[i] != '0')
			a = zero_print(format);
		if (handler->precision)
			b = put_precision_octal(string, format, handler, 1);
	}
	while (string[i] != '\0')
	{
		ft_putchar(string[i++]);
		format->count++;
	}
	while (i + b < handler->width - a)
	{
		ft_putchar(' ');
		i++;
		format->count++;
	}
}

void				print_octal(t_format *format,
											t_handler *handler, va_list arg)
{
	intmax_t		n;
	char			*string;

	string = NULL;
	if (handler->lenght == z)
		n = va_arg(arg, size_t);
	else if (handler->lenght == j)
		n = va_arg(arg, intmax_t);
	else if (handler->lenght == ll)
		n = va_arg(arg, long long);
	else if (handler->lenght == l)
		n = va_arg(arg, long);
	else if (handler->lenght == h)
		n = (unsigned short)va_arg(arg, int);
	else if (handler->lenght == hh)
		n = (unsigned char)va_arg(arg, int);
	else
		n = va_arg(arg, unsigned int);
	if (handler->type == octal)
		string = (printf_itoa_base_octal(n, 8));
	if (handler->flags.minus)
		print_octal_endwidth(string, format, handler);
	else
		print_octal_frontwidth(string, format, handler, '0');
	free(string);
}
