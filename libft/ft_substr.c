/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:09:00 by tseo              #+#    #+#             */
/*   Updated: 2020/10/06 20:09:35 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!len || ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (!s || !(str = (char*)malloc(sizeof(*s) * (len + 1))))
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
