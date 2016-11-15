/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:20:25 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/04 11:21:57 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_lowercase(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (!ft_islower(s[i]))
			return (0);
		i++;
	}
	return (1);
}
