/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:25:20 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/07 11:52:31 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*first;
	t_list	*tmp;

	res = NULL;
	while (lst != NULL)
	{
		tmp = (*f)(lst);
		if (res == NULL)
		{
			res = ft_lstnew(tmp->content, tmp->content_size);
			first = res;
		}
		else
		{
			res->next = ft_lstnew(tmp->content, tmp->content_size);
			res = res->next;
		}
		if (res == NULL)
			return (NULL);
		lst = lst->next;
	}
	return (first);
}
