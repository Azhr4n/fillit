/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 08:37:29 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/04 08:39:59 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (!s2[0])
		return (&(((char *)s1)[0]));
	while (i < n && s1[i])
	{
		if (s1[i] == s2[0])
		{
			y = 0;
			while (i + y < n && s1[i + y] == s2[y])
			{
				if (!s2[y + 1])
					return (&(((char *)s1)[i]));
				y++;
			}
		}
		i++;
	}
	return (NULL);
}
