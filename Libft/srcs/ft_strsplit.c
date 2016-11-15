/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:21:53 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/08 09:34:03 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_strcut(const char *s, char *val, char c, size_t *i)
{
	size_t	k;

	k = 0;
	while (s[*i] == c)
		*i += 1;
	while (s[*i] && s[*i] != c)
	{
		val[k] = s[*i];
		k++;
		*i += 1;
	}
	if (!s[*i] && k == 0)
		return (NULL);
	val[k] = '\0';
	return (val);
}

char		**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	**res;
	char	*val;

	size = ft_wordscutlen(s, c);
	if ((res = (char **)malloc(sizeof(*res)
					* (size + 1))) == NULL)
		return (NULL);
	res[size] = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((val = (char *)malloc(sizeof(*val)
						* (ft_wordcutlen(s, i, c) + 1))) == NULL)
			return (NULL);
		res[j] = ft_strcut(s, val, c, &i);
		if (res[j] == NULL)
			res[j] = 0;
		j++;
	}
	return (res);
}
