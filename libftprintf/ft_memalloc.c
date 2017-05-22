/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:47:00 by bskiba            #+#    #+#             */
/*   Updated: 2016/11/18 23:11:58 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	unsigned char	*s1;
	size_t			i;

	i = 0;
	if ((s1 = malloc(sizeof(void) * size)))
	{
		while (i != size)
			s1[i++] = 0;
		return (s1);
	}
	return (NULL);
}
