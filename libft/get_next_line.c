/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:34:57 by cpoulet           #+#    #+#             */
/*   Updated: 2017/01/24 16:02:59 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_stock(t_gnl **gnl, char *p_n)
{
	char	*tmp;

	if (p_n)
	{
		(*gnl)->excess = ft_strdup(p_n + 1);
		tmp = (*gnl)->buffer;
		(*gnl)->buffer = ft_strsub(tmp, 0, p_n - tmp);
		ft_strdel(&tmp);
	}
	else if ((tmp = ft_strchr((*gnl)->buffer, '\n')))
	{
		tmp = (*gnl)->buffer;
		(*gnl)->buffer = ft_strsub(tmp, 0, ft_strlen(tmp) - 1);
		ft_strdel(&tmp);
	}
}

static	void	ft_excess(t_gnl **gnl)
{
	char *tmp;

	if ((*gnl)->excess)
	{
		tmp = (*gnl)->buffer;
		(*gnl)->buffer = ft_strjoin((*gnl)->excess, (*gnl)->buffer);
		ft_strdel(&tmp);
		ft_strdel(&(*gnl)->excess);
	}
}

static int		readline(t_gnl **gnl)
{
	int		ret;
	char	*tmp;
	char	*buff;

	tmp = NULL;
	buff = ft_strnew(BUFF_SIZE);
	if (!(*gnl)->buffer)
		(*gnl)->buffer = ft_strnew(BUFF_SIZE);
	ft_excess(gnl);
	while (tmp == NULL && (ret = read((*gnl)->fd, buff, BUFF_SIZE)) > 0)
	{
		tmp = (*gnl)->buffer;
		(*gnl)->buffer = ft_strjoin((*gnl)->buffer, buff);
		ft_strdel(&tmp);
		ft_strclr(buff);
		tmp = ft_strchr((*gnl)->buffer, '\n');
	}
	tmp = ft_strchr((*gnl)->buffer, '\n');
	ft_strdel(&buff);
	if (ret == -1)
		return (-1);
	if (!*((*gnl)->buffer))
		return (0);
	ft_stock(gnl, tmp);
	return (1);
}

static t_gnl	*select_struct(const int fd, t_gnl **gnl)
{
	t_gnl	*elem;
	t_gnl	*svg;

	svg = (*gnl)->start;
	*gnl = svg;
	while ((*gnl)->next && (*gnl)->fd != fd)
		*gnl = (*gnl)->next;
	if ((*gnl)->fd == fd)
		return (*gnl);
	elem = (t_gnl*)malloc(sizeof(t_gnl));
	(*gnl)->next = elem;
	elem->fd = fd;
	elem->start = svg;
	elem->buffer = NULL;
	elem->excess = NULL;
	elem->next = NULL;
	return (elem);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (!gnl)
	{
		gnl = (t_gnl*)malloc(sizeof(t_gnl));
		gnl->fd = fd;
		gnl->excess = NULL;
		gnl->buffer = NULL;
		gnl->start = gnl;
		gnl->next = NULL;
	}
	if (gnl->fd != fd)
		gnl = select_struct(fd, &gnl);
	ret = readline(&gnl);
	*line = ft_strdup(gnl->buffer);
	ft_strdel(&gnl->buffer);
	return (ret);
}
