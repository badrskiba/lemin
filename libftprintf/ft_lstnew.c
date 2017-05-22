/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:58:58 by bskiba            #+#    #+#             */
/*   Updated: 2016/11/19 00:34:45 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*tmp;
	unsigned char	*tcontent;

	tcontent = (unsigned char*)malloc(sizeof(unsigned char) * content_size);
	if (tcontent == NULL)
		return (NULL);
	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->next = NULL;
		return (tmp);
	}
	else
	{
		tmp->content = ft_memcpy(tcontent, content, content_size);
		tmp->content_size = content_size;
		tmp->next = NULL;
	}
	return (tmp);
}
