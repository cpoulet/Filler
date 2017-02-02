/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:17:18 by cpoulet           #+#    #+#             */
/*   Updated: 2016/10/05 18:33:10 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] && i < size)
		i++;
	while (src[j])
		j++;
	j = i + j;
	if (i == size)
		return (j);
	while (i < size - 1 && *src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (j);
}
