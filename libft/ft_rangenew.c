/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rangenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:21:03 by cpoulet           #+#    #+#             */
/*   Updated: 2017/01/27 13:57:40 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_rangenew(size_t size)
{
	int *range;

	if (!(range = (int*)malloc(sizeof(int) * (size))))
		return (NULL);
	while (size != 0)
		range[--size] = 0;
	return (range);
}
