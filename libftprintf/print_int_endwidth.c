/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_endwidth.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:45:41 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 19:46:49 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					put_precision(t_format *format,
												t_handler *handler, char *str)
{
	unsigned int	i;
	int				a;

	a = 0;
	i = 0;
	i = (unsigned int)ft_strlen(str);
	if (i < handler->precision)
	{
		while (i < handler->precision)
		{
			ft_putchar('0');
			format->count++;
			a++;
			i++;
		}
	}
	return (a);
}

int					put_firstflag(t_format *format,
									t_handler *handler, intmax_t n, int nbn)
{
	int				a;

	a = 0;
	if (!nbn && handler->type == s_deci)
	{
		if (handler->flags.plus && n >= 0)
		{
			ft_putchar('+');
			a++;
			format->count++;
		}
		else if (handler->flags.space)
		{
			ft_putchar(' ');
			a++;
			format->count++;
		}
	}
	return (a);
}

void				put_width(t_format *format,
											t_handler *handler, char c, int i)
{
	while ((unsigned int)i < handler->width)
	{
		ft_putchar(c);
		format->count++;
		i++;
	}
}

void				print_int_endwidth(t_format *format,
									t_handler *handler, intmax_t n, int nbn)
{
	char			*string;
	int				i;
	int				a;

	i = 0;
	if (n == 0 && handler->precision == 0 &&
									handler->prec && !handler->flags.space)
		return ;
	string = ft_itoa_intmax(n);
	a = put_firstflag(format, handler, n, nbn);
	a += put_precision(format, handler, string);
	while (string[i] != '\0')
	{
		ft_putchar(string[i]);
		format->count++;
		i++;
	}
	if (handler->n)
		i++;
	put_width(format, handler, ' ', i + a);
	free(string);
}
