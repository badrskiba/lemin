/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_frontwidth.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:02:25 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 18:03:15 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			put_precision_udiff(t_format *format,
											t_handler *handler, char *string)
{
	unsigned int	i;

	i = 0;
	i = (unsigned int)ft_strlen(string);
	if (i < handler->precision)
	{
		while (i < handler->precision)
		{
			ft_putchar('0');
			format->count++;
			i++;
		}
	}
}

static void			print_uint_frontwidth_next(t_format *format,
								t_handler *handler, char *str, uintmax_t n)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
			put_precision_udiff(format, handler, str);
		if (n == 0 && handler->precision == 0
				&& handler->prec && handler->width)
			ft_putchar(' ');
		else
			ft_putchar(str[i]);
		format->count++;
		i++;
	}
	free(str);
}

void				print_uint_frontwidth(t_format *format,
		t_handler *handler, uintmax_t n, int nbn)
{
	char			*string;
	int				length;
	char			add;

	add = ' ';
	if (n == 0 && handler->precision == 0 && handler->prec && !handler->width)
		return ;
	if (handler->flags.zero && !handler->precision)
		add = '0';
	string = ft_itoa_uintmax(n);
	length = (unsigned int)ft_strlen(string) < handler->precision ?
		handler->precision : ft_strlen(string);
	length = handler->flags.plus && !nbn ? (length + 1) : length;
	if (nbn)
		length++;
	if (handler->flags.space)
		length++;
	if (add == ' ')
		put_width(format, handler, add, length);
	put_firstflag(format, handler, n, nbn);
	if (nbn)
		ft_putchar('-');
	if (add == '0')
		put_width(format, handler, add, length);
	print_uint_frontwidth_next(format, handler, string, n);
}
