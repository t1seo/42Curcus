/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:43:28 by tseo              #+#    #+#             */
/*   Updated: 2020/10/21 13:36:12 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_line(int fd, char **strs, char **line)
{
	char *ptr;
	char *tmp;

	if ((ptr = ft_strchr(strs[fd], '\n')))
	{
		*ptr = 0;
		*line = ft_strdup(strs[fd]);
		tmp = ft_strdup(ptr + 1);
		free(strs[fd]);
		strs[fd] = tmp;
		return (1);
	}
	else if (*strs[fd])
	{
		*line = ft_strdup(strs[fd]);
		free(strs[fd]);
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*strs[1023];
	char			buf[BUFFER_SIZE + 1];
	int				rd_size;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((rd_size = read(fd, buf, BUFFER_SIZE) > 0))
	{
		buf[rd_size] = '\0';
		strs[fd] = ft_strjoin(strs[fd], buf);
		if (ft_strchr(buf, '\n'))
			return (get_line(fd, strs, line));
	}
	return (get_line(fd, strs, line));
}
