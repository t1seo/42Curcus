/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:43:28 by tseo              #+#    #+#             */
/*   Updated: 2020/10/21 14:03:21 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_newline_idx(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

int		get_line(int fd, char **strs, char **line, int idx)
{
	char *tmp;

}

int		get_next_line(int fd, char **line)
{
	static char		*strs[1023];
	char			buf[BUFFER_SIZE + 1];
	int				rd_size;
	int				idx;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((rd_size = read(fd, buf, BUFFER_SIZE) > 0))
	{
		buf[rd_size] = '\0';
		strs[fd] = ft_strjoin(strs[fd], buf);
		if ((idx = get_newline_idx(strs[fd])) != -1)
			return (get_line(fd, strs, line, idx));
	}
	return (get_line(fd, strs, line, idx));
}
