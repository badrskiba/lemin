/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:08:01 by bskiba            #+#    #+#             */
/*   Updated: 2016/11/11 19:21:49 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *big, const char *little)
{
	const char	*tmp1;
	const char	*tmp2;

	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0')
	{
		tmp1 = big;
		tmp2 = little;
		while (*tmp1 == *tmp2 && *tmp1 != '\0' && *tmp2 != '\0')
		{
			tmp1++;
			tmp2++;
		}
		if (*tmp2 == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
