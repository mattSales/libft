/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:53:04 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/19 16:53:38 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_STRUCT_H
# define LIST_STRUCT_H

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

#endif