/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:36:18 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/04 11:37:39 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_uppercase(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isupper(s[i]))
			return (0);
		i++;
	}
	return (1);
}
