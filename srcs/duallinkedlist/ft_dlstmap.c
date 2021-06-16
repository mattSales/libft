/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:15:33 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/16 16:35:27 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "duallinkedlist.h"

t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*dst;

	if (!lst)
		return (NULL);
	if (f)
		dst = ft_dlstnew(f(lst->content));
	if (del && !dst->content)
	{
		ft_dlstclear(&lst, del);
		return (NULL);
	}
	dst->next = ft_dlstmap(lst->next, f, del);
	return (dst);
}
