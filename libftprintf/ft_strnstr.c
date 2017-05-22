/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:06:20 by bskiba            #+#    #+#             */
/*   Updated: 2016/11/11 19:19:36 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len1;
	int		a;

	a = 0;
	if (*little == '\0')
		return ((char *)big);
	len1 = ft_strlen(little);
	while (*big != '\0' && len >= len1)
	{
		if (*big == *little && ft_memcmp(big, little, len1) == 0)
		{
			a = 1;
			break ;
		}
		big++;
		len--;
	}
	if (a == 1)
		return ((char*)big);
	return (NULL);
}
