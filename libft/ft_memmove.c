/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:14:57 by msales-a          #+#    #+#             */
/*   Updated: 2020/02/08 17:59:21 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	size_t				index;
	unsigned char		*ptr0;
	const unsigned char	*ptr1;

	if (!dst && !src)
		return (0);
	if (!len || dst == src)
		return (dst);
	index = 0;
	ptr0 = (unsigned char *)dst;
	ptr1 = (unsigned char const *)src;
	if (ptr1 < ptr0)
		while (++index <= len)
			ptr0[len - index] = ptr1[len - index];
	else
		while (len--)
			*(ptr0++) = *(ptr1++);
	return (dst);
}
