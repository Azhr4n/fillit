/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:33:21 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/04 11:35:53 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_printable(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isprint(s[i]))
			return (0);
		i++;
	}
	return (1);
}
