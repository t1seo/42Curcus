/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbong <malbong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:45:25 by malbong           #+#    #+#             */
/*   Updated: 2020/10/01 15:51:34 by malbong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*cur_node;
	void	*new_content;
	t_list	*ret;
	t_list	*new_node;

	cur_node = lst;
	ret = NULL;
	while (cur_node != NULL)
	{
		new_content = f(cur_node->content);
		if ((new_node = ft_lstnew(new_content)) == NULL)
		{
			if (del != NULL)
				ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, new_node);
		cur_node = cur_node->next;
	}
	return (ret);
}
