/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:20:14 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/07 14:52:57 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstfold(int (*f)(int, int), int *list, int init)
{
	if (!list)
		return (init);
	else
		return ((*f)(list[0], ft_lstfold(f, &list[1], init)));
}
