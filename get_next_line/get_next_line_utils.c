/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:43:24 by tseo              #+#    #+#             */
/*   Updated: 2020/10/21 15:09:06 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *s)
{
	int		i;
	char	*ret;

	if (!(ret = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char		*ft_append(char *s1, char *s2)
{
	int		len;
	char	*str;
	int		i;

	if (!s1)
		s1 = malloc(1);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = -1;
	if (str)
	{
		while (*s1)
			str[++i] = *s1++;
		while (*s2)
			str[++i] = *s2++;
	}
	str[++i] = 0;
	// free(s1);
	return (str);
}
