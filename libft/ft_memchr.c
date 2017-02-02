/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:32:32 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/03 09:32:34 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *str;

	str = (char*)s;
	while (n-- != 0)
		if ((unsigned char)*str++ == (unsigned char)c)
			return (str - 1);
	return (0);
}
