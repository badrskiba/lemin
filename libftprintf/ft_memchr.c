/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:47:27 by bskiba            #+#    #+#             */
/*   Updated: 2016/11/11 17:53:48 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *tmp;
	size_t				i;

	tmp = s;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == (unsigned char)c)
			return ((char*)&tmp[i]);
		i++;
	}
	return (NULL);
}
