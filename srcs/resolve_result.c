/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:50:41 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/15 16:48:47 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include <stdlib.h>

static void		clean_tmp(t_core *core, char **tmp_result)
{
	UI	i;

	i = 0;
	while (i < core->max_square)
	{
		ft_bzero(tmp_result[i], sizeof(char) * core->max_square);
		i++;
	}
}

static int		fill_res(t_core *core, char **tmp_result)
{
	size_t		i;
	size_t		j;

	core->result = (char **)malloc(sizeof(char *) * (core->min_square + 1));
	if (core->result == NULL)
		return (-1);
	core->result[core->min_square] = 0;
	i = 0;
	while (i < core->min_square)
	{
		core->result[i] = (char *)malloc(sizeof(char) * (core->min_square + 1));
		if (core->result[i] == NULL)
			return (-1);
		j = 0;
		while (j < core->min_square)
		{
			core->result[i][j] = tmp_result[i][j];
			j++;
		}
		free(tmp_result[i++]);
	}
	while (i < core->max_square)
		free(tmp_result[i++]);
	free(tmp_result);
	return (0);
}

static int		ft_create_result(t_core *core, char ***tmp_result)
{
	size_t	y;
	float	ret;

	ret = ft_sqrtf(((float)core->piece) * 4);
	core->min_square = (size_t)ret;
	if (((int)ret) * 1000 < (int)(ret * 1000))
		core->min_square++;
	if (!(core->piece % 2))
		core->max_square = ((core->piece / 2) * 4) + 1;
	else
		core->max_square = (((core->piece / 2) + 1) * 4);
	if ((*tmp_result = (char **)malloc(sizeof(**tmp_result) *
					(core->max_square))) == NULL)
		return (-1);
	y = 0;
	while (y < core->max_square)
	{
		if (((*tmp_result)[y] = ft_strnew(core->max_square)) == NULL)
			return (-1);
		ft_bzero((*tmp_result)[y], sizeof(char) * core->max_square);
		y++;
	}
	return (0);
}

int				recursive_solve(t_core *core, char **tmp_result, size_t index)
{
	t_piece	piece;

	if (index == core->piece)
		return (1);
	piece.y = 0;
	while (piece.y < core->min_square)
	{
		piece.x = 0;
		while (piece.x < core->min_square)
		{
			piece.index = index;
			if (put_piece(core, tmp_result, &piece))
			{
				if (recursive_solve(core, tmp_result, index + 1) == 1)
					return (1);
				else
					reset_index(core, tmp_result, index);
			}
			piece.x++;
		}
		piece.y++;
	}
	return (0);
}

int				solve_result(t_core *core)
{
	char	**tmp_result;

	tmp_result = NULL;
	if (ft_create_result(core, &tmp_result) == -1)
		return (-1);
	while (1)
	{
		if (recursive_solve(core, tmp_result, 0) == 1)
		{
			if (fill_res(core, tmp_result) == -1)
				return (-1);
			break ;
		}
		core->min_square++;
		clean_tmp(core, tmp_result);
	}
	return (0);
}
