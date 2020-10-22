/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:43:09 by tseo              #+#    #+#             */
/*   Updated: 2020/10/22 22:38:36 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		get_line(char **strs, char **line, char *ptr, int fd)
{
	char *tmp;

	if (ptr != 0)
	{
		*ptr = 0;
		*line = ft_strdup(strs[fd]);
		tmp = ft_strdup(ptr + 1);
		free(strs[fd]);
		strs[fd] = tmp;
		return (SUCCESS);
	}
	if (strs[fd] != 0)
	{
		*line = strs[fd];
		strs[fd] = 0;
	}
	else
		*line = ft_strdup("");
	return (EOF_REACHED);
}

int				get_next_line(int fd, char **line)
{
	static char		*strs[MAX_FD];
	char			buf[BUFFER_SIZE + 1];
	int				rd_size;
	char			*ptr;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (ERROR);
	while ((ptr = ft_strchr(strs[fd], '\n')) == 0
			&& (rd_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_size] = 0;
		strs[fd] = ft_strappend(strs[fd], buf);
	}
	if (rd_size < 0)
		return (ERROR);
	return (get_line(strs, line, ptr, fd));
}
