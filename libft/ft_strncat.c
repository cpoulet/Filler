/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 17:17:18 by cpoulet           #+#    #+#             */
/*   Updated: 2016/09/05 12:33:10 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *rslt;

	rslt = dest;
	while (*dest)
		dest++;
	while (*src && n-- > 0)
		*dest++ = *src++;
	*dest = '\0';
	return (rslt);
}
