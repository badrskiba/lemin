/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_strlower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 02:31:04 by bskiba            #+#    #+#             */
/*   Updated: 2017/02/10 02:32:20 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*printf_strlower(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = str;
	while (tmp[i])
	{
		if (tmp[i] >= 'A' && str[i] <= 'Z')
			tmp[i] = tmp[i] + 32;
		i++;
	}
	return (tmp);
}

char		*printf_strupper(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = str;
	while (tmp[i])
	{
		if (tmp[i] >= 'a' && str[i] <= 'z')
			tmp[i] = tmp[i] - 32;
		i++;
	}
	return (tmp);
}
