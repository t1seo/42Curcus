/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:12:19 by heryu             #+#    #+#             */
/*   Updated: 2020/10/02 12:12:19 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_length;
	char	*ret;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	s_length = ft_strlen(s);
	if ((ret = (char *)malloc((s_length + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	while (i < s_length)
	{
		ret[i] = f((unsigned int)i, s[i]);
		i++;
	}
	ret[s_length] = '\0';
	return (ret);
}
