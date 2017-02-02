/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:06:51 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/07 09:35:45 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tab_to_lst(char **tab, t_list **alst)
{
	int		i;

	i = 0;
	if (tab && *tab && alst)
	{
		if (!*alst)
		{
			*alst = ft_lstnew(tab[i], ft_strlen(tab[i]) + 1);
			i++;
		}
		while (tab[i++])
			ft_lstaddend(alst, ft_lstnew(tab[i - 1],
						ft_strlen(tab[i - 1]) + 1));
	}
}
