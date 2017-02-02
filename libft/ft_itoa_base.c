/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 09:17:49 by cpoulet           #+#    #+#             */
/*   Updated: 2017/01/16 19:50:09 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define HEX "0123456789ABCDEF"

char	*ft_itoa_base(long long nb, int base)
{
	char	*str;
	int		neg;
	int		len;

	if (base < 2 || base > 16)
		return (NULL);
	neg = (base == 10 && nb < 0) ? 1 : 0;
	len = ft_nblen_b(nb, base) + neg;
	str = (char*)malloc(sizeof(str) * (len + 1));
	str[len] = '\0';
	if (!nb)
		str[0] = '0';
	while (nb != 0)
	{
		str[--len] = nb > 0 ? HEX[nb % base] : HEX[(nb % base) * -1];
		nb /= base;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
