/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:10:47 by heryu             #+#    #+#             */
/*   Updated: 2020/10/02 12:10:48 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr_b;
	size_t			i;

	i = 0;
	ptr_b = b;
	while (i < len)
	{
		*ptr_b++ = (unsigned char)c;
		i++;
	}
	return (b);
}
