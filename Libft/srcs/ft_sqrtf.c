/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrtf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:35:56 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/15 16:19:44 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_sqrtf(float x)
{
	float	precision;
	float	ux;

	precision = 0.001;
	ux = x;
	while ((ux * ux >= x + precision) || (ux * ux <= x - precision))
		ux = (ux + x / ux) / 2;
	return (ux);
}
