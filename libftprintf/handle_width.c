/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 02:39:43 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/10 02:41:50 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_width(t_format *format, t_handler *handler)
{
	unsigned int i;

	i = 0;
	while ((format->string[format->pos] >= '0') &&
			(format->string[format->pos] <= '9'))
	{
		i = i * 10 + (format->string[format->pos] - '0');
		format->pos++;
	}
	handler->width = i;
}
