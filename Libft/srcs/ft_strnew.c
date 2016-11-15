/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:03:47 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/07 09:52:22 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	if ((res = (char *)malloc(n + 1)) == NULL)
		return (NULL);
	while (i < n + 1)
		res[i++] = '\0';
	return (res);
}
