/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:31:30 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/07 09:52:42 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	len = ft_strlen(s);
	if ((res = ft_strnew(len)) == NULL)
		return (NULL);
	while (s[i])
	{
		res[i] = (*f)(s[i]);
		i++;
	}
	return (res);
}
