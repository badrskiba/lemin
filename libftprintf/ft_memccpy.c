/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:31:24 by bskiba            #+#    #+#             */
/*   Updated: 2016/11/11 14:24:39 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char		*tmp1;
	char			*tmp2;

	tmp1 = src;
	tmp2 = dst;
	while (n > 0)
	{
		*tmp2 = *tmp1;
		if (*tmp1 == c)
			return (tmp2 + 1);
		tmp1++;
		tmp2++;
		n--;
	}
	return (NULL);
}
