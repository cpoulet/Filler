/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:41:30 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/04 13:16:06 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char *str;
	char *ret;

	if (!s || !f)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	ret = str;
	while (*s)
		*str++ = f(*s++);
	return (ret);
}
