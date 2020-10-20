/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:11:09 by msales-a          #+#    #+#             */
/*   Updated: 2020/05/23 10:26:07 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned char		*ndst;
	unsigned char const	*nsrc;

	ndst = (unsigned char*)dst;
	nsrc = (unsigned char const *)src;
	if (!ndst && !nsrc)
		return (NULL);
	while (n-- > 0)
		*(ndst++) = (*(nsrc++) & 0xff);
	return (dst);
}
