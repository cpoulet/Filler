/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharnew_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:11:55 by cpoulet           #+#    #+#             */
/*   Updated: 2017/01/08 17:16:25 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcharnew_c(size_t size, char c)
{
	wchar_t *str;

	if (!(str = (wchar_t*)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (size != 0)
		str[--size] = c;
	return (str);
}
