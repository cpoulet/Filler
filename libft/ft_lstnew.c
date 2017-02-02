/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 10:11:03 by cpoulet           #+#    #+#             */
/*   Updated: 2016/11/05 13:40:35 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*elem;

	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		if (!(elem->content = ft_memalloc(content_size)))
			return (NULL);
		elem->content_size = content_size;
		ft_memcpy(elem->content, content, content_size);
	}
	elem->next = NULL;
	return (elem);
}
