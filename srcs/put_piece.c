/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:19:23 by pivanovi          #+#    #+#             */
/*   Updated: 2016/11/15 16:05:36 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		reset_index(t_core *core, char **map, int index)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < core->min_square)
	{
		j = 0;
		while (j < core->min_square)
		{
			if (map[i][j] == 'A' + index)
				map[i][j] = 0;
			j++;
		}
		i++;
	}
}

static UI	check_piece(char **map, t_piece *piece, UI val, size_t min_square)
{
	UI	i;

	i = 0;
	while (i < SIZE_PIECE)
	{
		if ((val & 1) && ((map[piece->y + (i / 4)][piece->x + (i % 4)])
			|| ((piece->y + (i / 4) >= min_square
				|| piece->x + (i % 4) >= min_square))))
			return (0);
		val >>= 1;
		i++;
	}
	return (1);
}

UI			put_piece(t_core *core, char **map, t_piece *piece)
{
	UI		i;
	UI		val;

	val = core->tab_piece[piece->index];
	if (!check_piece(map, piece, val, core->min_square))
		return (0);
	i = 0;
	while (i < SIZE_PIECE)
	{
		if ((val & 1) && !map[piece->y + (i / 4)][piece->x + (i % 4)])
			map[piece->y + (i / 4)][piece->x + (i % 4)] = 'A'
				+ piece->index;
		val >>= 1;
		i++;
	}
	return (1);
}
