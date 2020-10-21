/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:43:31 by tseo              #+#    #+#             */
/*   Updated: 2020/10/21 14:46:12 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

int		    get_next_line(int fd, char **line);
char        *ft_strjoin(char *s1, char *s2);
char	    *ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
char	    *ft_strchr(const char *s, int c);


#endif