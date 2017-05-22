/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:08:13 by bskiba            #+#    #+#             */
/*   Updated: 2016/11/17 20:14:27 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*tmp;

	if (s == NULL)
		return (NULL);
	i = 0;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	while (len--)
	{
		tmp[i] = s[i + start];
		i++;
	}
	tmp[i] = '\0';
	return ((char*)tmp);
}
