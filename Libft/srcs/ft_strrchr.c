/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 08:11:22 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/04 08:22:58 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	last;

	i = 0;
	last = 0;
	while (s[i])
	{
		if (s[i] == c)
			last = i;
		i++;
	}
	if (s[i] == c)
		last = i;
	if (s[last] == c)
		return (&(((char *)s)[last]));
	return (NULL);
}
