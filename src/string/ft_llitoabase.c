/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoabase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 20:30:23 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/16 11:08:21 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_llitoabase(long long number, char const *base)
{
	int			radix;
	int			index;
	char		*dst;
	long long	value;

	if (!base || !(radix = ft_strlen(base)))
		return (0);
	value = number < 0 ? -1 * number : number;
	index = ft_algs_num_base(number, radix) + (number < 0 ? 1 : 0);
	if (!(dst = malloc(sizeof(char) * (index + 1))))
		return (0);
	dst[index--] = '\0';
	dst[0] = '-';
	while (value)
	{
		dst[index--] = base[value % radix];
		value /= radix;
	}
	return (dst);
}
