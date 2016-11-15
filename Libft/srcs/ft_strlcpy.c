/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:12:36 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/10 10:40:42 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (n - i > 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (n - i > 0)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
