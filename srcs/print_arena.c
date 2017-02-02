/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:51:13 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/02 14:23:23 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void		points(t_arena *arena, char *line)
{
	line += 6;
	if (*line == 'O')
		arena->nb_o++;
	else if (*line == 'X')
		arena->nb_x++;
}

static void	progress(t_arena *arena)
{
	int i;
	int	max;
	int	ratio;
	int	sum;

	i = -1;
	sum = arena->nb_x + arena->nb_o;
	if (!sum)
		return ;
	max = (sum * 2 * arena->width) / sum;
	ratio = (arena->nb_o * 2 * arena->width) / sum;
	write(arena->fd, "\n\n       ", 9);
	while (++i <= ratio)
		ft_dprintf(arena->fd, BGCYN" "BGEOC);
	while (++i <= max + 1)
		ft_dprintf(arena->fd, BGMAG" "BGEOC);
	write(arena->fd, "\n", 1);
}

static void	print_map(t_arena *arena, char *line)
{
	int	i;

	i = -1;
	ft_dprintf(arena->fd, "   %03d  ", arena->line);
	line += 4;
	while (++i < arena->width)
	{
		if (line[i] == '.')
			ft_dprintf(arena->fd, GRN"."EOC);
		else if (line[i] == 'O')
			ft_dprintf(arena->fd, CYN"O"EOC);
		else if (line[i] == 'X')
			ft_dprintf(arena->fd, MAG"X"EOC);
		else if (line[i] == 'o' || line[i] == 'x')
			ft_dprintf(arena->fd, RED"%c"EOC, line[i]);
		write(arena->fd, " ", 1);
	}
}

static void	header(t_arena *arena)
{
	int i;

	i = -1;
	ft_dprintf(arena->fd, RED"\t\t _   _______\n\t\t| | / / ___/\n"CYN" > %s"
	" <"RED"\t| |/ (__  )\t"MAG"> %s <"RED"\n\t\t|___/____/\n\n"
	EOC, arena->name[0], arena->name[1]);
	write(arena->fd, "        ", 8);
	while (++i < arena->width)
		ft_dprintf(arena->fd, "%c ", NUM[i % 10]);
	write(arena->fd, "\n", 1);
}

void		show_fight(t_arena *arena, char *line)
{
	if (!arena->line)
	{
		ft_printf("\33[H");
		header(arena);
	}
	print_map(arena, line);
	write(arena->fd, "\n", 1);
	arena->line++;
	if (arena->line == arena->height)
	{
		progress(arena);
		usleep(20000);
		arena->line = 0;
	}
}
