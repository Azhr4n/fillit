/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:13:00 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/04 11:19:45 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_alpha(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isalpha(s[i]))
			return (0);
		i++;
	}
	return (1);
}
