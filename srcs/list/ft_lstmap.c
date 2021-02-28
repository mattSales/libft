/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:15:33 by msales-a          #+#    #+#             */
/*   Updated: 2020/05/23 10:23:52 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst;

	if (!lst)
		return (NULL);
	if (f)
		dst = ft_lstnew(f(lst->content));
	if (del && !dst->content)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	dst->next = ft_lstmap(lst->next, f, del);
	return (dst);
}
