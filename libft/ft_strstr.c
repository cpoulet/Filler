/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 09:47:15 by cpoulet           #+#    #+#             */
/*   Updated: 2016/08/11 21:48:24 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	if (!*to_find)
		return ((char*)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
			if (to_find[j++ + 1] == '\0')
				return ((char*)str + i);
		i++;
	}
	return (0);
}
