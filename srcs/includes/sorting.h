/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:48:47 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/16 00:18:07 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "libft.h"

/**
 * \brief Compare the size of two elements
 *
 * @param max The biggest element
 * @param min The smallest element
 *
 * @return Return true if the "max" is bigger than "min" element
 */
typedef bool (*	t_comparator)(void *max, void *min);

void	*heapsort(
			void *elements,
			size_t size,
			t_comparator comparator,
			int length);

#endif
