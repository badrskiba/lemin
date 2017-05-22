/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:45:39 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/12 16:41:03 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				read_string(t_format *format, va_list arg)
{
	format->pos = 0;
	while (format->string[format->pos])
	{
		if (format->string[format->pos] == '%'
										&& !format->string[format->pos + 1])
			break ;
		if (format->string[format->pos] == '%')
		{
			format->pos++;
			read_format(format, arg);
		}
		else
		{
			ft_putchar(format->string[format->pos]);
			format->count++;
			format->pos++;
		}
	}
}

int					ft_printf(char const *string, ...)
{
	t_format		format;
	va_list			arg;

	ft_bzero(&format, sizeof(format));
	format.string = string;
	va_start(arg, string);
	read_string(&format, arg);
	va_end(arg);
	return (format.count);
}
