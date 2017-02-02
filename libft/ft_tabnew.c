/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:42:15 by cpoulet           #+#    #+#             */
/*   Updated: 2017/01/25 13:03:47 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabnew(size_t height, size_t width)
{
	char **tab;

	if (!height || !width)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (height))))
		return (NULL);
	while (height-- != 0)
		tab[height] = ft_strnew(width);
	return (tab);
}
