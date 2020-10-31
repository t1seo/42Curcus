/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:09:06 by heryu             #+#    #+#             */
/*   Updated: 2020/10/02 14:32:25 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	str_rev(char *arr, size_t len)
{
	char	tmp;
	size_t	i;

	i = 0;
	while (i < len / 2)
	{
		tmp = arr[i];
		arr[i] = arr[len - 1 - i];
		arr[len - 1 - i] = tmp;
		i++;
	}
}

char		*ft_itoa(int n)
{
	int		sign;
	char	tmp[12];
	size_t	cnt;
	char	*ret;

	sign = (n < 0) ? -1 : 1;
	cnt = 0;
	while (1)
	{
		tmp[cnt++] = (sign * (n % 10)) + 0x30;
		n /= 10;
		if (n == 0)
			break ;
	}
	if (sign == -1)
		tmp[cnt++] = '-';
	str_rev(tmp, cnt);
	if ((ret = (char *)malloc((cnt + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(ret, tmp, cnt);
	ret[cnt] = '\0';
	return (ret);
}
