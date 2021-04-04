/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:07:02 by tseo              #+#    #+#             */
/*   Updated: 2021/04/04 18:55:39 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>

size_t		ft_strlen(char *str);
int			ft_strcmp(char const *s1, char const *s2);
char		*ft_strcpy(char *dst, char const *src);
ssize_t		ft_write(int fd, void const *buf, size_t nbyte);
ssize_t		ft_read(int fd, void *buf, size_t nbyte);
char		*ft_strdup(char const *s1);

#endif
