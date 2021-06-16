/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:48:05 by msales-a          #+#    #+#             */
/*   Updated: 2021/06/16 00:08:34 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

/**
 * \brief Swap two elements
 *
 * @param a First element
 * @param b Second element
 *
 * @return A pointer for the first element of NULL when it fails
 */
static void	*swap(void *a, void *b, size_t size)
{
	void	*c;

	if (!a || !b || !size)
		return (NULL);
	c = malloc(size);
	if (!c)
		return (NULL);
	ft_memmove(c, a, size);
	ft_memmove(a, b, size);
	ft_memmove(b, c, size);
	free(c);
	return (a);
}

/**
 * \brief Move element from bottom of the heap to the root
 *
 * @param e A list of elements to be sorted
 * @param s The size of an element
 * @param c A function able to compare two elements
 * @param l The number of elements
 *
 * @see heapsort()
 */
static void	heap_up(
	unsigned char *e,
	size_t s,
	t_comparator c,
	int l)
{
	int	p;

	while (true)
	{
		p = (l - 1) / 2;
		if (p < 0 || c(e + s * p, e + s * l))
			break ;
		swap(e + s * p, e + s * l, s);
		l = p;
	}
}

/**
 * \brief Move element from root to the bottom of the heap
 *
 * @param e A list of elements to be sorted
 * @param s The size of an element
 * @param c A function able to compare two elements
 * @param l The number of elements
 *
 * @see heapsort()
 */
static void	heap_down(
	unsigned char *e,
	size_t s,
	t_comparator c,
	int l)
{
	int	index;
	int	left;
	int	right;
	int	greater;

	index = 0;
	while (true)
	{
		left = 2 * index + 1;
		right = 2 * index + 2;
		if (left >= l && right >= l)
			break ;
		greater = left;
		if (right < l && c(e + s * right, e + s * left))
			greater = right;
		if (c(e + s * index, e + s * greater))
			break ;
		swap(e + s * index, e + s * greater, s);
		index = greater;
	}
}

/**
 * \brief Heapsort sort a list of elements
 *
 * @param elements A list of elements to be sorted
 * @param size The size of an element
 * @param comparator A function able to compare two elements
 * @param length The number of elements
 *
 * @return A pointer to the sorted array
 */
void	*heapsort(
	void *elements,
	size_t size,
	t_comparator comparator,
	int length)
{
	unsigned char	*ptr;
	int				index;

	if (!elements || !comparator || !size || length <= 0)
		return (NULL);
	ptr = (unsigned char *)elements;
	index = 0;
	while (++index < length)
		heap_up(ptr, size, comparator, index);
	while (length--)
	{
		swap(ptr + size * 0, ptr + size * length, size);
		heap_down(ptr, size, comparator, length);
	}
	return (elements);
}
