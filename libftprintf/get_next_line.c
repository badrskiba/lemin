/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 15:46:48 by bskiba            #+#    #+#             */
/*   Updated: 2017/05/10 17:16:57 by bskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list			*get_correct_file(t_list **file, int fd)
{
	t_list				*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

int						ft_count(char *src, char c)
{
	int					i;

	i = -1;
	while (src[++i])
	{
		if (src[i] == c)
			break ;
	}
	return (i);
}

char					*ft_strjoin1(char *s1, char *s2)
{
	char				*tmp;
	int					len;

	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	ft_strcpy(tmp, (char*)s1);
	ft_strcat(tmp, (char*)s2);
	ft_strdel(&s1);
	return (tmp);
}

char					*ft_strndup(char *s1, int n)
{
	char				*str;
	int					i;

	i = 0;
	str = (char *)malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] && i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int						get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	static t_list		*fds;
	int					i;
	int					ret;
	t_list				*list;

	if ((fd < 0 || !line || read(fd, buf, 0) < 0))
		return (-1);
	list = get_correct_file(&fds, fd);
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		list->content = (i++ == 0) ? ft_strjoin(list->content, buf)
			: ft_strjoin1(list->content, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!ft_strlen(list->content))
		return (0);
	i = ft_count(list->content, '\n');
	*line = ft_strndup(list->content, i);
	list->content = list->content + i + 1;
	return (1);
}
