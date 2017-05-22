/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:51:13 by bskiba            #+#    #+#             */
/*   Updated: 2016/11/11 17:55:43 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*tmp1;
	const char	*tmp2;

	tmp1 = s1;
	tmp2 = s2;
	while (n > 0)
	{
		if (*tmp1 != *tmp2)
			return ((unsigned char)*tmp1 - (unsigned char)*tmp2);
		tmp1++;
		tmp2++;
		n--;
	}
	return (0);
}
