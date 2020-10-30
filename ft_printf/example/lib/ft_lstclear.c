/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:09:31 by heryu             #+#    #+#             */
/*   Updated: 2020/10/02 12:09:31 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur_node;
	t_list	*del_node;

	cur_node = *lst;
	while (cur_node != NULL)
	{
		del_node = cur_node;
		cur_node = cur_node->next;
		ft_lstdelone(del_node, del);
	}
	*lst = NULL;
}
