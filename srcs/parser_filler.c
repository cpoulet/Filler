/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_filler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 11:52:30 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/01 11:22:32 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	error(const char *str, t_filler *filler)
{
	write(filler->fd, str, ft_strlen(str));
	filler->solve = -1;
}

static void	parse_map_piece(t_filler *filler, char **str, int line)
{
	int col;

	col = 0;
	while (**str && col < filler->p_width)
	{
		if (**str == '.' || **str == '*')
			filler->piece[line][col] = **str;
		else
			error("parsing error piece\n", filler);
		(*str)++;
		col++;
	}
	filler->line++;
}

static void	parse_map_line(t_filler *filler, char **str, int line)
{
	int col;

	col = 0;
	(*str) += 4;
	while (**str && col < filler->width)
	{
		if (**str == '.' || **str == 'X' || **str == 'x'
				|| **str == 'O' || **str == 'o')
			filler->map[line][col] = **str;
		else
			error("parsing error map\n", filler);
		(*str)++;
		col++;
	}
	filler->line++;
}

void		parse_player(t_filler *filler, char *line)
{
	int	nb;

	line += 10;
	nb = ft_atoi_skip(&line);
	filler->oim = nb == 1 ? 'O' : 'X';
	filler->adv = nb == 1 ? 'X' : 'O';
	filler->width = 0;
	filler->height = 0;
}

void		parse_map(t_filler *filler, char *line)
{
	if (!ft_strncmp(line, P1, 8) && filler->solve == 0)
	{
		line += 8;
		filler->height = ft_atoi_skip(&line);
		filler->width = ft_atoi_skip(&line);
		filler->map = ft_tab_i_new(filler->height, filler->width);
	}
	else if (*line == '*' || *line == '.')
	{
		if (filler->line < filler->p_height)
			parse_map_piece(filler, &line, filler->line);
		if (filler->line == filler->p_height)
			filler->solve = 2;
	}
	else if (!ft_strncmp(line, P2, 6))
	{
		line += 6;
		filler->p_height = ft_atoi_skip(&line);
		filler->p_width = ft_atoi_skip(&line);
		filler->piece = ft_tab_i_new(filler->p_height, filler->p_width);
		filler->line = 0;
	}
	else if (ft_isdigit(*line))
		if (filler->line < filler->height)
			parse_map_line(filler, &line, filler->line);
}
