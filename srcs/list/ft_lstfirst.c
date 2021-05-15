/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:07:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/14 22:17:15 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstfirst(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->previous)
		lst = lst->previous;
	return (lst);
}
