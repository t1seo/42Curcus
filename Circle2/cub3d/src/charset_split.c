/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charset_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:01:08 by tseo              #+#    #+#             */
/*   Updated: 2021/01/13 16:01:43 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		is_sep(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		++i;
	}
	return (0);
}

int		word_len(char *str, char *charset)
{
	int i;

	i = 0;
	while (str[i] != '\0' && !is_sep(str[i], charset))
		i++;
	return (i);
}

int		count_words(char *str, char *charset)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((i == 0 && !is_sep(str[i], charset)) ||
			(!is_sep(str[i - 1], charset) && is_sep(str[i], charset)))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	dest = (char *)malloc((n) * sizeof(char));
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	if (i < n && src[i] == '\0')
	{
		while (dest[i] != '\0')
		{
			dest[i] = '\0';
			++i;
		}
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_charset_split(char *str, char *charset)
{
	char	**array;
	int		word_flag;
	int		i;
	int		length;
	int		n_words;

	array = (char**)malloc(sizeof(char *) * count_words(str, charset) + 1);
	word_flag = 0;
	n_words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_sep(str[i], charset) && word_flag == 0)
		{
			word_flag = 1;
			length = word_len(&str[i], charset);
			array[n_words] = ft_strncpy(array[n_words], &str[i], length);
			++n_words;
		}
		else if (is_sep(str[i], charset))
			word_flag = 0;
		++i;
	}
	array[n_words] = 0;
	return (array);
}
