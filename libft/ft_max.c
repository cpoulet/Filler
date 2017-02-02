/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 11:51:48 by cpoulet           #+#    #+#             */
/*   Updated: 2017/01/26 12:17:46 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int n, ...)
{
	va_list	ap;
	int		ret;
	int		tmp;

	if (n == 0)
		return (0);
	va_start(ap, n);
	ret = va_arg(ap, int);
	while (--n > 0)
	{
		tmp = va_arg(ap, int);
		ret = tmp > ret ? tmp : ret;
	}
	va_end(ap);
	return (ret);
}
