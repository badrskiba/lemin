/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:57:41 by bskiba            #+#    #+#             */
/*   Updated: 2016/11/11 19:12:25 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	ft_strcpy(tmp, (char*)s1);
	ft_strcat(tmp, (char*)s2);
	return (tmp);
}
