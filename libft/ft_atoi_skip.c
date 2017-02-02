/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_skip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:20:16 by cpoulet           #+#    #+#             */
/*   Updated: 2017/01/25 12:57:25 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_skip(char **str)
{
	int rslt;
	int signe;

	rslt = 0;
	signe = 1;
	while ((**str >= 9 && **str <= 13) || **str == ' ')
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			signe = -1;
		(*str)++;
	}
	while (**str)
	{
		if (**str <= '9' && **str >= '0')
			rslt = rslt * 10 + **str - '0';
		else
			return (rslt * signe);
		(*str)++;
	}
	return (rslt * signe);
}
