/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:17:43 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/07 09:53:11 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	if ((res = ft_strnew(n)) == NULL)
		return (NULL);
	while (i < n && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}
