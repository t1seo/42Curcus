/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:12:52 by heryu             #+#    #+#             */
/*   Updated: 2020/10/02 12:12:53 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	substr_length;
	char	*ret;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < start && s[i] != '\0')
		i++;
	substr_length = 0;
	while (s[i] != '\0' && i - start < len)
	{
		substr_length++;
		i++;
	}
	if ((ret = (char *)malloc((substr_length + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(ret, s + start, substr_length);
	ret[substr_length] = '\0';
	return (ret);
}
