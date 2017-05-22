/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:13:49 by bskiba            #+#    #+#             */
/*   Updated: 2016/11/20 16:35:21 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t len;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (n == 0)
		return (1);
	if (*s1 == 0 && *s2 == 0)
		return (1);
	else if (*s2 == 0 || *s1 == 0)
		return (0);
	len = ft_strlen(s1) > ft_strlen(s2) ? ft_strlen(s1) : ft_strlen(s2);
	len = len > n ? n : len;
	return ((ft_strncmp(s1, s2, len) == 0));
}
