/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strredim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:52:15 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/12 13:49:27 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strredim(char *s, size_t size)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(s) + size + 1);
	tmp = ft_strncpy(tmp, s, ft_strlen(s));
	ft_strdel(&s);
	return (tmp);
}
