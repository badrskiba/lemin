/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:51:14 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 17:26:15 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cheek_capital(char a, t_handler *handler)
{
	if (a == 'D' || a == 'S' || a == 'C' || a == 'O' || a == 'U')
		handler->lenght = l;
}

int		valid_type(char a, t_handler *handler)
{
	if (a == 'd' || a == 'D' || a == 'i')
	{
		handler->type = s_deci;
	}
	else if (a == 'u' || a == 'U')
		handler->type = us_deci;
	else if (a == 'c' || a == 'C')
		handler->type = chr;
	else if (a == 'x')
		handler->type = hex_lower;
	else if (a == 'X')
		handler->type = hex_upper;
	else if (a == 'o' || a == 'O')
		handler->type = octal;
	else if (a == 's' || a == 'S')
		handler->type = str;
	else if (a == 'p')
		handler->type = pointer;
	else if (a >= 37 && a <= 122)
		handler->type = pourc;
	else
		return (0);
	return (1);
}

void	handle_type(t_format *format, t_handler *handler)
{
	while (format->string[format->pos] == ' ' ||
			format->string[format->pos] == '\t' ||
			format->string[format->pos] == '\n' ||
			format->string[format->pos] == '\v' ||
			format->string[format->pos] == '\f' ||
			format->string[format->pos] == '\r')
		format->pos++;
	while ((format->string[format->pos] >= 0 &&
			format->string[format->pos] <= 36) ||
			(format->string[format->pos] >= 38 &&
			format->string[format->pos] <= 64) ||
			(format->string[format->pos] >= 91 &&
			format->string[format->pos] <= 96))
		format->pos++;
	if (valid_type(format->string[format->pos], handler))
	{
		cheek_capital(format->string[format->pos], handler);
		format->pos++;
	}
	else
		handler->type = rien;
}
