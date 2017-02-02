/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:42:41 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/03 09:42:42 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = (int)ft_strlen(str);
	while (i >= 0)
		if (str[i--] == (char)c)
			return ((char*)&str[i + 1]);
	return (0);
}
