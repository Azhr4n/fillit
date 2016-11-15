/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:40:02 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/07 12:50:18 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*res;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (!s[i])
		return (ft_strnew(0));
	j = i;
	while (s[i])
		i++;
	while (i > 0 && (s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n'))
		i--;
	if ((res = ft_strnew(i - j)) == NULL)
		return (NULL);
	k = 0;
	while (s[j] && j < i)
	{
		res[k] = s[j];
		k++;
		j++;
	}
	return (res);
}
