/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:08:40 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/08 09:34:25 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_itoalen(int n, unsigned int nb, int size)
{
	if (size == 0)
		nb = n;
	if (n < 0)
	{
		nb = -n;
		size++;
	}
	size++;
	if (nb > 9)
		return (ft_itoalen(0, nb / 10, size));
	return (size);
}

char		*ft_itoa(int n)
{
	unsigned int	nb;
	size_t			len;
	char			*res;

	nb = 0;
	len = ft_itoalen(n, 0, 0);
	if ((res = (char *)malloc(sizeof(*res) * (len + 1))) == NULL)
		return (NULL);
	res[len--] = '\0';
	nb = n;
	if (n < 0)
	{
		res[0] = '-';
		nb = -n;
	}
	while (nb > 9)
	{
		res[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	res[len] = nb + '0';
	return (res);
}
