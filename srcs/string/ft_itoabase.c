/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 20:30:23 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:47:45 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_itoabase(int number, char const *base)
{
	int			radix;
	int			index;
	char		*dst;
	long long	value;

	radix = ft_strlen(base);
	if (!base || !radix)
		return (0);
	value = ft_abs(number);
	index = ft_algs_num_base(number, radix) + (number < 0);
	dst = malloc(sizeof(char) * (index + 1));
	if (!dst)
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
