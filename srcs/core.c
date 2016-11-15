/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:12:15 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/15 16:50:28 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "libft.h"

static void	print_result(t_core *core)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < core->min_square)
	{
		j = 0;
		while (j < core->min_square)
		{
			if (!core->result[i][j])
				ft_putchar('.');
			else
				ft_putchar(core->result[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int			main(int ac, char **av)
{
	t_core	core;

	if (ac > 1)
	{
		ft_reset_core(&core);
		if (ft_init_core(av[1], &core) == -1)
		{
			ft_putstr_fd("error\n", 1);
			return (1);
		}
		if (solve_result(&core) == -1)
		{
			ft_putstr_fd("error\n", 1);
			return (1);
		}
		print_result(&core);
	}
	else
		ft_putstr_fd("usage: fillit source_file\n", 1);
	return (0);
}
