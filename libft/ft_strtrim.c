/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:44:02 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/04 13:37:00 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	unsigned int i;
	unsigned int j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = ft_strlen(s);
	if (i == j)
		return (ft_strsub(s, 0, 0));
	while (j != 0 && (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t'))
		j--;
	return (ft_strsub(s, i, (size_t)(j - i)));
}
