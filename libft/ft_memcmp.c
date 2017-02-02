/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:32:57 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/03 09:33:10 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char *str1;
	char *str2;

	str1 = (char*)s1;
	str2 = (char*)s2;
	while (n-- != 0)
		if ((unsigned char)*str1++ != (unsigned char)*str2++)
			return ((unsigned char)*(str1 - 1) - (unsigned char)*(str2 - 1));
	return (0);
}
