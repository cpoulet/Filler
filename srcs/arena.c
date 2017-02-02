/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:48:25 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/02 14:22:18 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

int			ft_getline(const int fd, char **line)
{
	char	buff[2];
	char	*dup;
	char	*tmp;
	int		ret;

	dup = ft_strnew(0);
	while ((ret = read(fd, buff, 1)) > 0)
	{
		buff[1] = 0;
		if (!ft_strcmp(buff, "\n"))
			break ;
		tmp = dup;
		dup = ft_strjoin(dup, buff);
		ft_strdel(&tmp);
	}
	*line = ft_strdup(dup);
	ft_strdel(&dup);
	return (ret);
}

static void	arena_player(t_arena *arena, char *line)
{
	int nb;
	int i;

	i = 0;
	line += 10;
	nb = ft_atoi_skip(&line);
	line += 12;
	while (ft_strncmp(line, ".filler", 7))
		arena->name[nb - 1][i++] = *line++;
	while (i < 15)
		arena->name[nb - 1][i++] = '\0';
}

static void	arena_size(t_arena *arena, char *line)
{
	line += 8;
	arena->height = ft_atoi_skip(&line);
	arena->width = ft_atoi_skip(&line);
}

static void	arena_init(t_arena *arena)
{
	arena->fd = open("test", O_RDWR | O_APPEND | O_CREAT);
	arena->end = 1;
	arena->fd = 1;
	arena->line = 0;
	arena->nb_x = 0;
	arena->nb_o = 0;
	ft_printf("\033[H\033[J");
}

int			main(void)
{
	t_arena		arena;
	char		*line;

	arena_init(&arena);
	while (arena.end)
	{
		ft_getline(0, &line);
		if (!ft_strncmp(line, "$$$", 3))
			arena_player(&arena, line);
		else if (!ft_strncmp(line, "Plateau", 7))
			arena_size(&arena, line);
		else if (!ft_strncmp(line, "<got (", 6))
			points(&arena, line);
		else if (!ft_strncmp(line, "==", 2))
		{
			win(&arena);
			arena.end = 0;
		}
		else if (ft_isdigit(*line))
			show_fight(&arena, line);
		ft_strdel(&line);
	}
	return (0);
}
