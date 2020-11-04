/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:23:37 by tseo              #+#    #+#             */
/*   Updated: 2020/11/04 14:19:47 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib.h"

char		*ft_strappend(char *s1, char *s2)
{
	char *tmp;

	if (!s1)
	{
		s1 = ft_strdup(s2);
		return (s1);
	}
	else
	{
		tmp = ft_strjoin(s1, s2);
		free(s1);
		s1 = tmp;
		return (s1);
	}
}
