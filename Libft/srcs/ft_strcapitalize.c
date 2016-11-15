/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:52:23 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/04 12:18:51 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (ft_islower(s[i]))
		{
			if (i == 0)
				s[i] = ft_toupper(s[i]);
			else if (!ft_isalnum(s[i - 1]))
				s[i] = ft_toupper(s[i]);
		}
		else if (ft_isupper(s[i]))
			if (i != 0 && ft_isalnum(s[i - 1]))
				s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}
