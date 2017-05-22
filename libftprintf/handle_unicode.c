/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unicode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:26:30 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 17:43:32 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			count_bytes(unsigned int *count, wint_t wint)
{
	if (wint <= 0x7F)
		*count += 1;
	else if (wint <= 0x7FF)
		*count += 2;
	else if (wint <= 0xFFFF)
		*count += 3;
	else if (wint <= 0x10FFFF)
		*count += 4;
}

static void		sub_bytes(unsigned int *count, wint_t wint)
{
	if (wint <= 0x7F)
		*count -= 1;
	else if (wint <= 0x7FF)
		*count -= 2;
	else if (wint <= 0xFFFF)
		*count -= 3;
	else if (wint <= 0x10FFFF)
		*count -= 4;
}

unsigned int	max_bytes(wchar_t *string,
														t_handler *handler)
{
	size_t			i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (string[i])
	{
		count_bytes(&count, string[i]);
		if (handler->prec)
		{
			if (count > handler->precision)
			{
				sub_bytes(&count, string[i]);
				break ;
			}
		}
		i++;
	}
	return (count);
}
