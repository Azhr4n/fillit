/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:55:33 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/04 11:05:37 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	size_t	i;
	int		res;
	int		neg;

	i = 0;
	res = 0;
	neg = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-')
		neg = 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res *= 10;
		res += s[i] - '0';
		i++;
	}
	if (neg)
		return (-res);
	return (res);
}
