/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:59:55 by msales-a          #+#    #+#             */
/*   Updated: 2020/05/23 10:25:55 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *n;

	n = b;
	while (len--)
		*n++ = (((unsigned char)c) & 0xff);
	return (b);
}
