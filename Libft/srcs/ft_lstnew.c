/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:54:02 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/07 14:11:38 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	size_t	i;
	t_list	*res;
	char	*val;

	i = 0;
	if ((res = (t_list *)malloc(sizeof(*res))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		if ((val = (void *)malloc(content_size)) == NULL)
			return (NULL);
		while (i++ < content_size)
			val[i - 1] = ((unsigned char *)content)[i - 1];
		res->content = val;
		res->content_size = content_size;
	}
	res->next = NULL;
	return (res);
}
