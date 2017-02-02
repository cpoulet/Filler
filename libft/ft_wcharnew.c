/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:09:05 by cpoulet           #+#    #+#             */
/*   Updated: 2017/01/08 17:10:19 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcharnew(size_t size)
{
	wchar_t *str;

	if (!(str = (wchar_t*)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	while (size != 0)
		str[size--] = '\0';
	str[0] = '\0';
	return (str);
}
