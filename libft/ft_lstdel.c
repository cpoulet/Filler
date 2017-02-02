/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:27:35 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/03 09:27:38 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*elem;

	while (*alst)
	{
		elem = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = elem;
	}
	*alst = NULL;
}
