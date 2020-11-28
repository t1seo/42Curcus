/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 10:48:06 by tseo              #+#    #+#             */
/*   Updated: 2020/10/29 19:51:57 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t n)
{
	unsigned char	*b;

	b = (unsigned char*)ptr;
	while (n-- > 0)
		*(b++) = (unsigned char)value;
	return (ptr);
}
