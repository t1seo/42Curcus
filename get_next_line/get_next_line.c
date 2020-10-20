/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:43:28 by tseo              #+#    #+#             */
/*   Updated: 2020/10/20 20:06:25 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	// before new line should be allocated at 'line'

	// after new line should be allocated at 'strs[fd]'
}

int		get_next_line(int fd, char **line)
{
	static char		*strs[1023];
	char			buf[BUFFER_SIZE + 1];
	int				r_size;
	int				idx;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((r_size = read(fd, buf, BUFFER_SIZE) > 0))
	{
		buf[r_size] = '\0';
		strs[fd] = ft_strjoin(strs[fd], buf);
		if ((idx = get_newline_idx(strs[fd])) != -1)


		// check new line of strs[fd]
		// if strs[fd] has new line character -> get_line

	}

	// need to add exceptions
	// r < 0
	// r == 0 && strs[fd] == NULL
	// else return 1 by using get_line
}
