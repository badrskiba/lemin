/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:33:32 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 20:37:52 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(t_format *format, t_handler *handler, va_list arg)
{
	if (handler->lenght == l)
	{
		print_widestr(format, handler, va_arg(arg, wchar_t *));
		return ;
	}
	else
		print_normal_str(format, handler, va_arg(arg, char *));
}
