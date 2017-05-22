/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 02:33:32 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/10 02:34:06 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_arg(t_format *format, t_handler *handler, va_list arg)
{
	if (handler->type == s_deci || handler->type == us_deci)
		print_int(format, handler, arg);
	else if (handler->type == chr)
		print_chr(format, handler, arg);
	else if (handler->type == hex_upper || handler->type == hex_lower)
		print_hex(format, handler, arg);
	else if (handler->type == octal)
		print_octal(format, handler, arg);
	else if (handler->type == str)
		print_str(format, handler, arg);
	else if (handler->type == pointer)
	{
		handler->flags.hashtag = 1;
		handler->lenght = z;
		print_hex(format, handler, arg);
	}
	else if (handler->type == pourc)
		print_pourcent(format, handler);
}

void			read_format(t_format *format, va_list arg)
{
	t_handler	handler;

	ft_bzero(&handler, sizeof(handler));
	handle_flags(format, &handler);
	handle_width(format, &handler);
	handle_precision(format, &handler);
	handle_length(format, &handler);
	handle_type(format, &handler);
	if (handler.type == rien)
	{
		return ;
	}
	else
		print_arg(format, &handler, arg);
}
