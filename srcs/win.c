/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:49:23 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/02 14:08:14 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

void	win(t_arena *arena)
{
	if (arena->nb_o > arena->nb_x)
	{
		ft_dprintf(arena->fd, CYN"\n\n    ____ ___   _       _______   __\n"
		"   / __ <  /  | |     / /  _/ | / /\n  / /_/ / /   | | /| / // // "
		" |/ /\n / ____/ /    | |/ |/ // // /|  /\n/_/   /_/     |__/|__/__"
		"_/_/ |_/""\n\n");
		ft_dprintf(arena->fd, " Filler Champ of %s won %d to %d\n\n\n",
		arena->name[0], arena->nb_o, arena->nb_x);
	}
	else
	{
		ft_dprintf(arena->fd, MAG"\n\n    ____ ___      _       _______   _"
		"_\n   / __ \\__ \\    | |     / /  _/ | / /\n  / /_/ /_/ /    | | "
		"/| / // //  |/ /\n / ____/ __/     | |/ |/ // // /|  /\n/_/   /___"
		"_/     |__/|__/___/_/ |_/\n\n");
		ft_dprintf(arena->fd, " Filler Champ of %s won %d to %d\n\n\n",
		arena->name[1], arena->nb_x, arena->nb_o);
	}
}
