/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repeatchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:08:45 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/27 10:30:33 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_repeatchr(unsigned char c, int times)
{
	unsigned char *result;

	times = (times < 0) ? 0 : times;
	result = ft_calloc(times + 1, sizeof(unsigned char));
	ft_memset(result, c, times);
	return ((char*)result);
}
