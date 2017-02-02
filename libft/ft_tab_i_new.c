/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_i_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:42:15 by cpoulet           #+#    #+#             */
/*   Updated: 2017/01/26 11:23:39 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_tab_i_new(size_t height, size_t width)
{
	int **tab;

	if (!height || !width)
		return (NULL);
	if (!(tab = (int**)malloc(sizeof(int*) * (height))))
		return (NULL);
	while (height-- != 0)
		tab[height] = ft_rangenew(width);
	return (tab);
}
