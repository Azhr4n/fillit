/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:45:29 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/04 10:47:02 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isgraph(int c)
{
	if (ft_isprint(c) && !ft_isblank(c))
		return (1);
	return (0);
}