/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:57:53 by bskiba            #+#    #+#             */
/*   Updated: 2016/11/18 18:35:11 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		n_neg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n = *n * (-1);
		*neg = 1;
	}
}

char			*ft_itoa(int n)
{
	int		tmp;
	int		len;
	int		neg;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	len = 1;
	neg = 0;
	n_neg(&n, &neg);
	while (tmp /= 10)
		len++;
	len = len + neg;
	if ((str = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = n % 10 + '0';
		n = n / 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
