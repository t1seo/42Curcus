/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:12:38 by heryu             #+#    #+#             */
/*   Updated: 2020/10/02 12:12:39 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s_begin;

	s_begin = s;
	while (*s != '\0')
		s++;
	while (s != s_begin - 1 && *s != (char)c)
		s--;
	if (s == s_begin - 1)
		return (NULL);
	return ((char *)s);
}
