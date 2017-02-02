/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:04:55 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/01 11:24:51 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	fill_nb(t_filler *filler, int i, int nb)
{
	int flag;

	flag = 0;
	if (COL(i) != 0)
		if (CASE(i, i - 1) == '.' && ++flag)
			CASE(i, i - 1) = nb + 1;
	if (LINE(i) != 0)
		if (CASE(i - filler->width, i) == '.' && ++flag)
			CASE(i - filler->width, i) = nb + 1;
	if (COL(i) != filler->width - 1)
		if (CASE(i, i + 1) == '.' && ++flag)
			CASE(i, i + 1) = nb + 1;
	if (LINE(i) != filler->height - 1)
		if (CASE(i + filler->width, i) == '.' && ++flag)
			CASE(i + filler->width, i) = nb + 1;
	return (flag);
}

static void	fill_zero(t_filler *filler, int i)
{
	if (COL(i) != 0)
		if (CASE(i, i - 1) == '.')
			CASE(i, i - 1) = 130;
	if (LINE(i) != 0)
		if (CASE(i - filler->width, i) == '.')
			CASE(i - filler->width, i) = 130;
	if (COL(i) != filler->width - 1)
		if (CASE(i, i + 1) == '.')
			CASE(i, i + 1) = 130;
	if (LINE(i) != filler->height - 1)
		if (CASE(i + filler->width, i) == '.')
			CASE(i + filler->width, i) = 130;
}

static void	fill_init(t_filler *filler, char c)
{
	int i;

	i = -1;
	while (++i <= MAX)
		if (is_c(filler, LINE(i), COL(i), c))
			fill_zero(filler, i);
}

void		fill_map(t_filler *filler, char c)
{
	int i;
	int nb;
	int flag;

	fill_init(filler, c);
	nb = 129;
	flag = 1;
	while (flag && ++nb)
	{
		flag = 0;
		i = -1;
		while (++i <= MAX)
		{
			if (CASE(i, i) == nb)
				flag += fill_nb(filler, i, nb);
		}
	}
	i = -1;
	while (++i <= MAX)
	{
		if (CASE(i, i) == '.')
			CASE(i, i) = 200;
	}
}
