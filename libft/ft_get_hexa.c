/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:51:33 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/26 16:16:47 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_hexa(const char *str)
{
	int ret;

	ret = 0;
	if (*str == '0' && *(str + 1) == 'x')
		str += 2;
	while (ft_ishexa(*str))
	{
		if (*str >= 97)
			ret = ret * 16 + (ft_isdigit(*str++) ?
					*(str - 1) - 48 : *(str - 1) - 87);
		else
			ret = ret * 16 + (ft_isdigit(*str++) ?
					*(str - 1) - 48 : *(str - 1) - 55);
	}
	return (ret);
}
