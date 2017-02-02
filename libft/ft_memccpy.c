/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:32:20 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/04 12:20:40 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n-- != 0)
	{
		*(unsigned char*)dst++ = *(unsigned char*)src++;
		if (*(unsigned char*)(src - 1) == (unsigned char)c)
			return (dst);
	}
	return (0);
}
