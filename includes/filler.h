/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 15:53:25 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/02 14:27:27 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define P0			"$$$ exec p"
# define P1			"Plateau "
# define P2			"Piece "

# define LINE(x)	((x) / filler->width)
# define COL(x)		((x) % filler->width)
# define CASE(x, y)	(filler->map[LINE(x)][COL(y)])
# define MAX		(filler->width * filler->height - 1)
# define LINEP(x)	((x) / filler->p_width)
# define COLP(x)	((x) % filler->p_width)
# define MAXP		(filler->p_width * filler->p_height - 1)
# define REPL		(LINE(m) - LINEP(p))
# define REPC		(COL(m) - COLP(p))

typedef struct	s_filler
{
	int			fd;
	int			width;
	int			height;
	int			p_width;
	int			p_height;
	char		oim;
	char		adv;
	int			**map;
	int			**piece;
	int			val;
	int			x_ideal;
	int			y_ideal;
	int			line;
	int			solve;
}				t_filler;

int				is_c(t_filler *filler, int p1, int p2, char c);
void			marche_jarvis(t_filler *filler, char c);
void			parse_player(t_filler *filler, char *line);
void			parse_map(t_filler *filler, char *line);
void			fill_map(t_filler *filler, char c);
void			seg(t_filler *filler, int p1, int p2);
void			put_piece(t_filler *filler, char c);

#endif
