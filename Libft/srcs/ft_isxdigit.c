/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:10:33 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/04 11:41:45 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isxdigit(int c)
{
	if (ft_isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}
