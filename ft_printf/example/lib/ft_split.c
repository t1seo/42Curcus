/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:11:32 by heryu             #+#    #+#             */
/*   Updated: 2020/10/02 12:11:32 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(char const *s, char delim)
{
	size_t	i;
	int		flag;
	size_t	split_size;

	flag = 0;
	i = 0;
	split_size = 0;
	while (s[i] != '\0')
	{
		if (s[i] != delim && flag == 0)
		{
			split_size++;
			flag = 1;
		}
		if (s[i] == delim && flag == 1)
		{
			flag = 0;
		}
		i++;
	}
	return (split_size);
}

static void		*free_mem(char **allocated_mem, size_t cnt)
{
	size_t	i;

	i = 0;
	while (i < cnt)
	{
		free(allocated_mem[i]);
		i++;
	}
	free(allocated_mem);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	pivot;
	size_t	cnt;

	if (!s || !(ret = (char **)malloc((get_size(s, c) + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			pivot = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			if ((ret[cnt] = ft_substr(s, pivot, i - pivot)) == NULL)
				return (free_mem(ret, cnt));
			cnt++;
			continue ;
		}
		i++;
	}
	ret[cnt] = NULL;
	return (ret);
}
