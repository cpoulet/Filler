/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:43:02 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/04 13:48:38 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	i = 0;
	while (i++ < len)
		str[i - 1] = s[i - 1 + start];
	str[len] = '\0';
	return (str);
}
