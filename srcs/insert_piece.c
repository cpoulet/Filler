/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:12:46 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/02 14:22:50 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_val(t_filler *filler, int m, int p)
{
	int val;
	int i;
	int	l;
	int c;

	val = 0;
	i = -1;
	while (++i <= MAXP)
	{
		if (filler->piece[LINEP(i)][COLP(i)] == '*' && i != p)
		{
			l = REPL + LINEP(i);
			c = REPC + COLP(i);
			if (l < 0 || c < 0)
				return (-1);
			if (l >= filler->height || c >= filler->width)
				return (-1);
			if (filler->map[l][c] >= 130)
				val += filler->map[l][c] - 130;
			else
				return (-1);
		}
	}
	return (val);
}

static void	check_piece(t_filler *filler, int pos)
{
	int	i;
	int tmp;

	i = -1;
	while (++i <= MAXP)
	{
		if (filler->piece[LINEP(i)][COLP(i)] == '*')
		{
			tmp = check_val(filler, pos, i);
			if (tmp > 0 && tmp <= filler->val)
			{
				filler->solve = 1;
				filler->val = tmp;
				filler->x_ideal = COL(pos) - COLP(i);
				filler->y_ideal = LINE(pos) - LINEP(i);
			}
		}
	}
}

static void	del_piece(t_filler *filler)
{
	while (filler->p_height--)
		free(filler->piece[filler->p_height]);
	free(filler->piece);
}

void		put_piece(t_filler *filler, char c)
{
	int i;

	i = -1;
	filler->val = 2147483647;
	filler->solve = -1;
	while (++i <= MAX)
	{
		if (is_c(filler, LINE(i), COL(i), c))
			check_piece(filler, i);
	}
	if (filler->solve == 1)
		ft_dprintf(1, "%d %d\n", filler->y_ideal, filler->x_ideal);
	else
		ft_dprintf(1, "%d %d\n", 0, 0);
	del_piece(filler);
}
