/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:49:45 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/02 14:26:23 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include "libft.h"

# define NUM	"0123456789"
# define BGEOC	"\x1B[40m"
# define BGMAG	"\x1B[45m"
# define BGCYN	"\x1B[46m"

typedef struct	s_arena
{
	int			fd;
	int			height;
	int			width;
	char		name[2][15];
	int			end;
	int			line;
	int			nb_x;
	int			nb_o;
}				t_arena;

void			show_fight(t_arena *arena, char *line);
void			points(t_arena *arena, char *line);
void			win(t_arena *arena);

#endif
