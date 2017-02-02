/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jarvis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 10:52:49 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/01 11:32:20 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	seg_hor(t_filler *filler, int p1, int c, char k)
{
	int i;

	if (k == '+')
	{
		i = filler->width;
		while (--i > COL(p1))
		{
			if (is_c(filler, LINE(p1), i, c))
				k = 0;
			if (!k && filler->map[LINE(p1)][i] == '.')
				filler->map[LINE(p1)][i] = 130;
		}
	}
	else
	{
		i = -1;
		while (++i < COL(p1))
		{
			if (is_c(filler, LINE(p1), i, c))
				k = 0;
			if (!k && filler->map[LINE(p1)][i] == '.')
				filler->map[LINE(p1)][i] = 130;
		}
	}
}

static int	next_jarvis_r(t_filler *filler, char c, int p1)
{
	float	a;
	float	tmp;
	int		p2;
	int		p3;

	p3 = -1;
	a = -999999;
	p2 = p1 + (filler->width - COL(p1)) - filler->width - 1;
	while (--p2 > 0)
	{
		if (is_c(filler, LINE(p2), COL(p2), c))
		{
			tmp = (float)(COL(p1) - COL(p2)) / (LINE(p2) - LINE(p1));
			if (tmp >= a)
			{
				a = tmp;
				p3 = p2;
			}
			p2 = p2 + (filler->width - COL(p2)) - filler->width - 1;
		}
	}
	if (p3 != -1)
		seg(filler, p1, p3);
	return (p3);
}

static int	next_jarvis(t_filler *filler, char c, int p1)
{
	float	a;
	float	tmp;
	int		p2;
	int		p3;

	p3 = -1;
	a = -999999;
	p2 = p1 + (filler->width - COL(p1)) - 1;
	while (++p2 < MAX)
	{
		if (is_c(filler, LINE(p2), COL(p2), c))
		{
			tmp = (float)(COL(p1) - COL(p2)) / (LINE(p2) - LINE(p1));
			if (tmp >= a)
			{
				a = tmp;
				p3 = p2;
			}
			p2 = p2 + (filler->width - COL(p2));
		}
	}
	if (p3 != -1)
		seg(filler, p1, p3);
	return (p3);
}

static void	marche_jarvis_r(t_filler *filler, char c)
{
	int	i;
	int j;

	i = MAX + 1;
	j = -1;
	while (j == -1 && --i > 0)
		if (is_c(filler, LINE(i), COL(i), c))
			j = i;
	seg_hor(filler, j, c, '-');
	while (--i > 0)
	{
		if (is_c(filler, LINE(i), COL(i), c))
		{
			j = next_jarvis_r(filler, c, j);
			i = j != -1 ? j : 0;
		}
	}
	fill_map(filler, filler->adv);
}

void		marche_jarvis(t_filler *filler, char c)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	while (j == -1 && ++i < MAX)
		if (is_c(filler, LINE(i), COL(i), c))
			j = i;
	seg_hor(filler, j, c, '+');
	while (++i < MAX)
	{
		if (is_c(filler, LINE(i), COL(i), c))
		{
			j = next_jarvis(filler, c, j);
			i = j != -1 ? j : MAX;
		}
	}
	marche_jarvis_r(filler, c);
}
