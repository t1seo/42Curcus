/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:11:46 by heryu             #+#    #+#             */
/*   Updated: 2020/10/02 12:11:46 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	s_length;

	s_length = ft_strlen(s1);
	if ((ret = (char *)malloc((s_length + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(ret, s1, s_length * sizeof(char));
	ret[s_length] = '\0';
	return (ret);
}
