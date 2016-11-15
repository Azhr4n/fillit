/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:11:07 by pivanovi          #+#    #+#             */
/*   Updated: 2016/11/15 12:58:34 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static int	is_valid(UI value)
{
	static UI	pieces_value[NB_PIECES] = {	O_1, I_1, I_2, S_1, S_2, Z_1, Z_2,
		T_1, T_2, T_3, T_4, L_1, L_2, L_3, L_4, J_1, J_2, J_3, J_4};
	UI			i;

	i = 0;
	while (i < NB_PIECES)
	{
		if (value == pieces_value[i])
			return (1);
		i++;
	}
	return (0);
}

static UI	shift_left(char piece[SIZE_PIECE])
{
	UI		i;
	UI		y;
	int		first;

	i = 0;
	first = -1;
	while (i < SIZE_PIECE)
	{
		if (piece[i] && first == -1)
		{
			first = i % 4;
			y = i / 4;
		}
		else if (piece[i] && first != -1 && y < (i / 4) && i % 4 < (UI)first)
			return ((UI)first - (i % 4));
		i++;
	}
	return (0);
}

UI			get_piece_value(char piece[SIZE_PIECE])
{
	int		i;
	UI		value;
	int		index;

	i = -1;
	index = -1;
	while (index == -1 && ++i < SIZE_PIECE)
	{
		if (piece[i])
			index = i;
	}
	if (index != -1)
	{
		value = 0;
		i = (UI)index - 1;
		while (++i < SIZE_PIECE)
			value += piece[i] << (i - (UI)index);
		value <<= shift_left(piece);
		if (is_valid(value))
			return (value);
	}
	return (0);
}
