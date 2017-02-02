/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:27:00 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/03 09:27:10 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*elem;

	if (alst && *alst)
	{
		elem = *alst;
		while (elem->next)
			elem = elem->next;
		if (new)
			elem->next = new;
	}
}
