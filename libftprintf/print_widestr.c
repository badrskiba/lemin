/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:35:09 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 20:38:46 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			widestr_endwidth(t_format *format, t_handler *handler,
												char fill, wchar_t *string)
{
	int				i;
	unsigned int	max;
	unsigned int	count;

	i = 0;
	max = max_bytes(string, handler);
	count = 0;
	while (string[i])
	{
		count_bytes(&count, string[i]);
		if (handler->prec)
			if (count > max)
				break ;
		print_wint(string[i], format);
		i++;
	}
	while (max < handler->width)
	{
		print_wint(fill, format);
		max++;
	}
}

static void			widestr_frontwidth(t_format *format,
							t_handler *handler, char fill, wchar_t *string)
{
	size_t			i;
	unsigned int	max;

	max = max_bytes(string, handler);
	i = 0;
	while (i + max < handler->width)
	{
		print_wint(fill, format);
		i++;
	}
	i = 0;
	max = 0;
	while (string[i])
	{
		count_bytes(&max, string[i]);
		if (handler->prec)
			if (max > handler->precision)
				break ;
		print_wint(string[i], format);
		i++;
	}
}

void				print_widestr(t_format *format,
										t_handler *handler, wchar_t *string)
{
	char			fill;

	if (handler->flags.zero)
		fill = '0';
	else
		fill = ' ';
	if (!string)
	{
		print_normal_str(format, handler, "(null)");
		return ;
	}
	if (handler->flags.minus)
		widestr_endwidth(format, handler, fill, string);
	else
		widestr_frontwidth(format, handler, fill, string);
}
