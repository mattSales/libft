/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:04:48 by msales-a          #+#    #+#             */
/*   Updated: 2020/02/08 17:59:03 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	unsigned char const	*psrc;
	unsigned char		*pdst;
	unsigned char		k;
	int					index;

	psrc = src;
	pdst = dst;
	k = c;
	index = 0;
	while (n--)
	{
		pdst[index] = psrc[index];
		if (k == psrc[index])
			return (pdst + ++index);
		index++;
	}
	return (0);
}
