/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:22:44 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/03 09:22:52 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int rslt;
	int signe;

	rslt = 0;
	signe = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (*str++ != '\0')
	{
		if (*(str - 1) <= '9' && *(str - 1) >= '0')
			rslt = rslt * 10 + (*(str - 1) - '0');
		else
			return (rslt * signe);
	}
	return (rslt * signe);
}
