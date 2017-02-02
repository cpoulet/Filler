/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:31:30 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/07 09:33:49 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*tmp;
	t_list	*ret;

	ret = NULL;
	if (f && lst)
	{
		if (!(elem = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		elem = f(lst);
		ret = elem;
		lst = lst->next;
		while (lst)
		{
			if (!(tmp = (t_list*)malloc(sizeof(t_list))))
				return (NULL);
			tmp = f(lst);
			elem->next = tmp;
			elem = tmp;
			lst = lst->next;
		}
		elem->next = NULL;
	}
	return (ret);
}
