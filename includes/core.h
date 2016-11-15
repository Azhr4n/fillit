/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:01:26 by pivanovi          #+#    #+#             */
/*   Updated: 2016/11/15 16:38:20 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# define SIZE_PIECE 16
# define MAX_PIECE 26
# define UI unsigned int

# include <unistd.h>

enum
{
	O_1 = 51,
	I_1 = 4369,
	I_2 = 15,
	S_1 = 54,
	S_2 = 561,
	Z_1 = 99,
	Z_2 = 306,
	T_1 = 39,
	T_2 = 562,
	T_3 = 114,
	T_4 = 305,
	L_1 = 785,
	L_2 = 23,
	L_3 = 547,
	L_4 = 116,
	J_1 = 802,
	J_2 = 113,
	J_3 = 275,
	J_4 = 71,
	NB_PIECES = 19
};

typedef struct	s_piece
{
	UI			x;
	UI			y;
	UI			index;
}				t_piece;

typedef struct	s_core
{
	size_t		piece;
	size_t		min_square;
	size_t		max_square;
	UI			*tab_piece;
	char		**result;
}				t_core;

void			ft_reset_core(t_core *core);
int				ft_init_core(char *file, t_core *core);
UI				get_piece_value(char piece[SIZE_PIECE]);
int				solve_result(t_core *core);
UI				put_piece(t_core *core, char **tmp_result, t_piece *piece);
void			reset_index(t_core *core, char **map, int index);

#endif
