/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:26:50 by msales-a          #+#    #+#             */
/*   Updated: 2020/05/23 10:20:56 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (*lst)
	{
		ft_lstclear(&((*lst)->next), del);
		del((*lst)->content);
		free(*lst);
		*lst = 0;
	}
}
