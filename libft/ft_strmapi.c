/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:41:41 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/04 13:17:23 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(str = ft_strdup(s)))
		return (NULL);
	while (s[i++])
		str[i - 1] = f(i - 1, s[i - 1]);
	return (str);
}
