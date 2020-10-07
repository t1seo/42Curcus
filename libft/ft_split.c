/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 10:31:41 by tseo              #+#    #+#             */
/*   Updated: 2020/10/07 12:39:12 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t count;

	count = 0;
	while (*s)
	{
		count++;
		while (*s && (*s != c))
			s++;
		while (*s == c)
			s++;
	}
	return (count);
}

static char		**fill_words(char **arr, char const *s, char c)
{
	size_t	idx;
	char	*start;

	idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char*)s;
			while (*s && *s != c)
				s++;
			if (!(arr[idx] = (char*)malloc(s - start + 1)))
				return (0);
			ft_strlcpy(arr[idx], start, s - start + 1);
			idx++;
		}
		else
			s++;
	}
	arr[idx] = 0;
	return (arr);
}

char			**ft_split(char const *s, char c)
{
	char	**word_arr;

	if (!s)
		return (0);
	if (!(word_arr = (char**)malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (0);
	word_arr = fill_words(word_arr, s, c);
	return (word_arr);
}
