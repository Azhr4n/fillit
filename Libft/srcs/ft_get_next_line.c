/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 07:16:50 by achauvea          #+#    #+#             */
/*   Updated: 2016/11/15 11:44:34 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int			create_line(t_next_line *elem_core,
		char **line, char *new, int free)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (new == NULL || (tmp = ft_strdup(new)) == NULL)
		return (-1);
	if (free)
		ft_strdel(&new);
	ft_strdel(&(elem_core->more));
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
	{
		if ((*line = ft_strsub(tmp, 0, i)) == NULL)
			return (-1);
		if ((elem_core->more = ft_strdup(&tmp[i + 1])) == NULL)
			return (-1);
		ft_strdel(&tmp);
		return (1);
	}
	else if ((elem_core->more = ft_strdup(tmp)) == NULL)
		return (-1);
	ft_strdel(&tmp);
	return (0);
}

static t_next_line	*create_core(const int fd, t_next_line **core)
{
	t_next_line	*tmp;
	t_next_line	*res;

	res = *core;
	while (res)
	{
		if (res->fd == fd)
			return (res);
		if (!res->next)
			break ;
		res = res->next;
	}
	if ((tmp = (t_next_line*)malloc(sizeof(*tmp))) == NULL)
		return (NULL);
	tmp->fd = fd;
	tmp->more = NULL;
	tmp->next = NULL;
	if (!(*core))
		*core = tmp;
	else
		res->next = tmp;
	return (tmp);
}

static int			read_next_line(const int fd, char **line,
		t_next_line *elem_core)
{
	int		ret;
	int		ret_line;
	char	buf[BUFF_SIZE + 1];

	if (elem_core->more)
		if ((ret_line = create_line(elem_core, line, elem_core->more, 0)) != 0)
			return (ret_line);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (elem_core->more)
		{
			if ((ret_line = create_line(elem_core, line,
						ft_strjoin(elem_core->more, buf), 1)) != 0)
				return (ret_line);
		}
		else
		{
			if ((ret_line = create_line(elem_core, line, buf, 0)) != 0)
				return (ret_line);
		}
	}
	if (ret == -1)
		return (-1);
	return (0);
}

static void			end_next_line(t_next_line **core, t_next_line *elem_core)
{
	t_next_line	*tmp;

	if ((*core)->fd == elem_core->fd)
		*core = (*core)->next;
	else
	{
		tmp = *core;
		while (tmp)
		{
			if (tmp->next && tmp->next->fd == elem_core->fd)
				break ;
			tmp = tmp->next;
		}
		tmp->next = elem_core->next;
	}
	ft_strdel(&(elem_core->more));
	free(elem_core);
}

int					ft_get_next_line(const int fd, char **line)
{
	static t_next_line	*core;
	t_next_line			*elem_core;
	int					ret_line;

	if ((elem_core = create_core(fd, &core)) == NULL)
		return (-1);
	if ((ret_line = read_next_line(fd, line, elem_core)) != 0)
		return (ret_line);
	if (elem_core->more && ft_strlen(elem_core->more) > 0)
	{
		if ((*line = ft_strdup(elem_core->more)) == NULL)
			return (-1);
		ft_strdel(&(elem_core->more));
		return (1);
	}
	end_next_line(&core, elem_core);
	return (0);
}
