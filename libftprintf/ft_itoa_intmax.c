/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_intmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:31:59 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/09 15:32:26 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_itoa_intmax(intmax_t n)
{
	intmax_t	tmp;
	int			len;
	int			neg;
	char		*str;

	tmp = n;
	len = 1;
	neg = 0;
	while (tmp /= 10)
		len++;
	len = len + neg;
	if ((str = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len] = n % 10 < 0 ? (n % 10) * -1 + '0' : n % 10 + '0';
		len--;
		n = n / 10;
	}
	if (neg == 1 && str[1] != '-')
		str[0] = '-';
	return (str);
}
