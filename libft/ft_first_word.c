/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:25:50 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/04 12:32:07 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_first_word(const char *s, char c)
{
	size_t	len;
	char	*str;

	while (*s == c && *s)
		s++;
	len = 0;
	while (s[len] != c && s[len])
		len++;
	if (len == 0)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str = ft_strncpy(str, s, len);
	return (str);
}
