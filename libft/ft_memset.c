/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 10:48:06 by tseo              #+#    #+#             */
/*   Updated: 2020/10/06 20:15:51 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t n)
{
	void *ret;

	if (!ptr)
		return (NULL);
	ret = ptr;
	while (n--)
		*(char*)ptr++ = (unsigned char)value;
	return (ret);
}
