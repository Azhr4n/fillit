/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:13:23 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/07 10:46:56 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (n - len > 0 && dest[len])
		len++;
	while (n - len - i > 1 && src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	if (n - len > 0)
		dest[len + i] = '\0';
	while (src[i])
		i++;
	return (len + i);
}
