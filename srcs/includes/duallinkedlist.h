/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duallinkedlist.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 09:33:01 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/18 18:23:16 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUALLINKEDLIST_H
# define DUALLINKEDLIST_H

# include "libft.h"

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*previous;
}					t_dlist;

t_dlist	*ft_dlstnew(void *content);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *neww);
int		ft_dlstsize(t_dlist *lst);
t_dlist	*ft_dlstlast(t_dlist *lst);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *neww);
void	ft_dlstdelone(t_dlist *lst, void (*del)(void*));
void	ft_dlstclear(t_dlist **lst, void (*del)(void*));
void	ft_dlstiter(t_dlist *lst, void (*f)(void *));
t_dlist	*ft_dlstmap(t_dlist *l, void *(*f)(void *), void (*del)(void *));
t_dlist	*ft_dlstfirst(t_dlist *lst);
t_dlist	*ft_dlstpop(t_dlist **lst, t_dlist *element);

#endif
