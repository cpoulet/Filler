/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 11:53:10 by cpoulet           #+#    #+#             */
/*   Updated: 2017/02/02 13:49:28 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_getline(const int fd, char **line)
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

int		main(void)
{
	t_filler	filler;
	char		*line;

	filler.solve = 0;
	while (filler.solve != -1)
	{
		ft_getline(0, &line);
		if (!ft_strncmp(line, P0, 10))
			parse_player(&filler, line);
		else if (*line == ' ')
			filler.line = 0;
		else
			parse_map(&filler, line);
		if (filler.solve == 2)
		{
			if (!filler.width || !filler.height)
				ft_dprintf(1, "Naughty correcteur !\n");
			marche_jarvis(&filler, filler.adv);
			put_piece(&filler, filler.oim);
		}
		ft_strdel(&line);
	}
	return (0);
}
