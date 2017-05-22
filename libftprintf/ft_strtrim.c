/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:09:15 by bskiba            #+#    #+#             */
/*   Updated: 2016/11/18 18:13:21 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*tmp;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	j = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t'))
		j--;
	if (i > j)
		return (ft_strdup(s + i));
	tmp = ft_strsub(s, i, (j - i));
	return (tmp);
}
