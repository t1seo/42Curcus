/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:43:24 by tseo              #+#    #+#             */
/*   Updated: 2020/10/21 14:45:57 by tseo             ###   ########.fr       */
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

// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s != (unsigned char)c)
// 	{
// 		if (*s == 0)
// 			return (0);
// 		++s;
// 	}
// 	return ((char*)s);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		len;
// 	char	*str;
// 	int		i;

// 	if (!s1 || !s2)
// 		return (0);
// 	len = ft_strlen(s1) + ft_strlen(s2);
// 	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
// 		return (0);
// 	i = -1;
// 	if (str)
// 	{
// 		while (*s1)
// 			str[++i] = *s1++;
// 		while (*s2)
// 			str[++i] = *s2++;
// 	}
// 	str[++i] = '\0';
// 	return (str);
// }

size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (dstsize == 0)
	{
		return (src_len);
	}
	i = 0;
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (src_len);
}

size_t		ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && dest_len + 1 + i < dstsize)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (dstsize < dest_len)
		return (dstsize + src_len);
	return (dest_len + src_len);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		s1_len;
	int		s2_len;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_strlcpy(newstr, s1, s1_len + 1);
	free(s1);
	ft_strlcat(newstr + (s1_len), s2, s2_len + 1);
	return (newstr);
}
