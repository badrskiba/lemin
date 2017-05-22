/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_itoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 02:23:30 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/10 02:24:48 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strrev(char *str, intmax_t n)
{
	int		i;
	int		length;
	char	tmp;

	i = 0;
	if (str[0] == '\0' && n == 0)
	{
		str[0] = '0';
		i++;
		str[i] = '\0';
		return (str);
	}
	if (str)
	{
		i = 0;
		length = ft_strlen(str);
		while (i < length / 2)
		{
			tmp = str[i];
			str[i] = str[length - i - 1];
			str[length - i - 1] = tmp;
			i++;
		}
	}
	return (str);
}

char		*printf_itoa_base(uintmax_t n, int base)
{
	int		i;
	char	*s;
	char	*keys;

	keys = ft_strdup("0123456789abcdef");
	s = NULL;
	s = malloc(sizeof(char) * 33);
	if (!s)
		return (0);
	i = 0;
	while (n >= 10)
	{
		s[i] = keys[n % base];
		n = n / base;
		i++;
	}
	if (n < 10 && n > 0)
	{
		s[i] = keys[n];
		i++;
	}
	s[i] = '\0';
	ft_strrev(s, n);
	free(keys);
	return (s);
}
