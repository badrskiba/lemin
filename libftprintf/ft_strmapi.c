/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:01:29 by bskiba            #+#    #+#             */
/*   Updated: 2016/11/11 19:14:50 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	tmp = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (tmp == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		tmp[i] = f(i, s[i]);
		i++;
	}
	tmp[i] = '\0';
	return ((char*)tmp);
}
