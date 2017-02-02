/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 16:39:46 by cpoulet           #+#    #+#             */
/*   Updated: 2016/08/16 16:00:32 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(*str) * (ft_strlen(src) + 1))))
		return (NULL);
	ft_strcpy(str, src);
	return (str);
}
