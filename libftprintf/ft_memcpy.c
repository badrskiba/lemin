/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:27:02 by bskiba            #+#    #+#             */
/*   Updated: 2016/11/18 18:45:44 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmp1;
	char	*tmp2;

	tmp2 = (char*)dst;
	tmp1 = (char*)src;
	if (n == 0 || dst == src)
		return (dst);
	while (--n)
		*tmp2++ = *tmp1++;
	*tmp2 = *tmp1;
	return (dst);
}
