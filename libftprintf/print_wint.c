/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:35:00 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 17:43:54 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_chars(void *str, int size, t_format *format)
{
	write(1, str, size);
	format->count += size;
}

static void		print_wint_next(wint_t wint, t_format *format)
{
	char	str[4];

	str[0] = (((wint & 0x1c0000) >> 18) + 0xF0);
	str[1] = (((wint & 0x03F000) >> 12) + 0x80);
	str[2] = (((wint & 0x0Fc0) >> 6) + 0x80);
	str[3] = ((wint & 0x003F) + 0x80);
	print_chars(str, 4, format);
}

void			print_wint(wint_t wint, t_format *format)
{
	char str[4];

	if (wint <= 0x7F)
	{
		write(1, &wint, 1);
		format->count++;
	}
	else if (wint <= 0x7FF)
	{
		str[0] = (((wint & 0x07c0) >> 6) + 0xc0);
		str[1] = ((wint & 0x003F) + 0x80);
		print_chars(str, 2, format);
	}
	else if (wint <= 0xFFFF)
	{
		str[0] = (((wint & 0xF000) >> 12) + 0xE0);
		str[1] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[2] = ((wint & 0x003F) + 0x80);
		print_chars(str, 3, format);
	}
	else if (wint <= 0x10FFFF)
		print_wint_next(wint, format);
}
