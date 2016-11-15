/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:55:03 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/15 16:38:55 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void		ft_reset_core(t_core *core)
{
	core->piece = 0;
	core->min_square = 0;
	core->max_square = 0;
	core->tab_piece = 0;
	core->result = NULL;
}

int			ft_create_tab_piece(t_core *core,
			UI tmp_tab_piece[SIZE_PIECE])
{
	size_t	i;

	if ((core->tab_piece = (UI *)malloc(sizeof(*(core->tab_piece)) *
					(core->piece))) == NULL)
		return (-1);
	i = 0;
	while (i < core->piece)
	{
		core->tab_piece[i] = tmp_tab_piece[i];
		i++;
	}
	return (0);
}

static int	reset_piece(t_core *core, char *line, size_t *boucle)
{
	*boucle += 1;
	if (*boucle == 5)
	{
		if (line[0])
			return (-1);
		else
			*boucle = 0;
	}
	else if (*boucle == 4)
		core->piece += 1;
	return (0);
}

static char	*parse_piece(char piece[SIZE_PIECE], char *line, size_t boucle)
{
	size_t	i;

	i = 0;
	while (line[i] && i < 4)
	{
		if (line[i] == '.')
			piece[boucle * 4 + i] = 0;
		else if (line[i] == '#')
			piece[boucle * 4 + i] = 1;
		else
			return (NULL);
		i++;
	}
	if (line[i] || (boucle != 4 && i != 4))
		return (NULL);
	return (piece);
}

int			ft_init_core(char *file, t_core *core)
{
	int		array_return[2];
	char	*line;
	char	piece[SIZE_PIECE];
	size_t	boucle;
	UI		tmp_tab_piece[MAX_PIECE];

	if ((array_return[0] = open(file, O_RDONLY)) == 1)
		return (-1);
	boucle = 0;
	while ((array_return[1] = (ft_get_next_line(array_return[0], &line))) > 0)
	{
		if ((parse_piece(piece, line, boucle)) == NULL)
			return (-1);
		free(line);
		if (boucle == 3 &&
				(tmp_tab_piece[core->piece] = get_piece_value(piece)) == 0)
			return (-1);
		if (reset_piece(core, line, &boucle) == -1)
			return (-1);
	}
	if (close(array_return[0] == -1) || boucle != 4 ||
			core->piece > MAX_PIECE || array_return[1] == -1 ||
				ft_create_tab_piece(core, tmp_tab_piece) == -1)
		return (-1);
	return (0);
}
