/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:04:55 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/02 14:24:14 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			is_c(t_filler *filler, int p1, int p2, char c)
{
	if (filler->map[p1][p2] == c || filler->map[p1][p2] == c + 32)
		return (1);
	return (0);
}

static void	seg_ver(t_filler *filler, int p1, int p2)
{
	int i;

	i = LINE(p1);
	if (i < LINE(p2))
		while (++i < LINE(p2) && filler->map[i][COL(p1)] == '.')
			filler->map[i][COL(p1)] = 130;
	else
		while (--i > LINE(p2) && filler->map[i][COL(p1)] == '.')
			filler->map[i][COL(p1)] = 130;
}

static void	seg_col(t_filler *filler, int p1, int p2, float a)
{
	int		i;
	float	k;

	i = 0;
	if (COL(p1) < COL(p2))
	{
		k = a * i + LINE(p1);
		while (i + COL(p1) <= COL(p2))
		{
			if (filler->map[ft_approx(k)][i + COL(p1)] == '.')
				filler->map[ft_approx(k)][i + COL(p1)] = 130;
			k = a * ++i + LINE(p1);
		}
	}
	else
	{
		k = a * i + LINE(p2);
		while (i + COL(p2) <= COL(p1))
		{
			if (filler->map[ft_approx(k)][i + COL(p2)] == '.')
				filler->map[ft_approx(k)][i + COL(p2)] = 130;
			k = a * ++i + LINE(p2);
		}
	}
}

void		seg(t_filler *filler, int p1, int p2)
{
	float a;

	if (COL(p1) == COL(p2))
	{
		seg_ver(filler, p1, p2);
		return ;
	}
	a = (float)(LINE(p2) - LINE(p1)) / (COL(p2) - COL(p1));
	if (-1 <= a && a <= 1)
		seg_col(filler, p1, p2, a);
}
