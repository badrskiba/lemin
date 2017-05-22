/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_Uint_endwidth.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:45:54 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 17:46:58 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_ufirstflag(t_format *format,
											t_handler *handler)
{
	int		a;

	a = 0;
	if (handler->type == s_deci)
	{
		if (handler->flags.plus)
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

void		print_uint_endwidth(t_format *format,
											t_handler *handler, uintmax_t n)
{
	char	*string;
	int		i;
	int		a;

	i = 0;
	if (n == 0 && handler->precision == 0
									&& handler->prec && !handler->flags.space)
	{
		return ;
	}
	string = ft_itoa_uintmax(n);
	a = put_ufirstflag(format, handler);
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
