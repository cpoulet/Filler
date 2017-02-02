/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 09:13:06 by cpoulet           #+#    #+#             */
/*   Updated: 2016/12/01 09:13:58 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_nb_b(const char *str, int base)
{
	int ret;

	ret = 0;
	if (*str == '0' && *(str + 1) == 'x')
		str += 2;
	while (ft_ishexa(*str))
	{
		if (*str >= 97)
			ret = ret * base + (ft_isdigit(*str++) ?
					*(str - 1) - 48 : *(str - 1) - 87);
		else
			ret = ret * base + (ft_isdigit(*str++) ?
					*(str - 1) - 48 : *(str - 1) - 55);
	}
	return (ret);
}
