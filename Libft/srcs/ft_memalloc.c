/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:07:00 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/04 15:49:22 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t n)
{
	void	*res;

	if ((res = (void *)malloc(sizeof(*res) * n)) == NULL)
		return (NULL);
	res = ft_memset(res, '\0', n);
	return (res);
}
