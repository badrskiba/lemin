/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:45:03 by bskiba            #+#    #+#             */
/*   Updated: 2016/11/11 17:52:38 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int n;
	int tmp;

	n = 1;
	tmp = 0;
	while (*str == '\t' || *str == '\v' || *str == '\n' || *str == '\f'
			|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	while (*str && *str > 47 && *str < 58)
	{
		tmp = tmp * 10 + (*str - 48);
		str++;
	}
	return (tmp * n);
}
