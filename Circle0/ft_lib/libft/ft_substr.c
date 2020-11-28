/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:09:00 by tseo              #+#    #+#             */
/*   Updated: 2020/11/04 14:19:05 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s || !len || ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (!(str = (char*)malloc(sizeof(*s) * (len + 1))))
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
