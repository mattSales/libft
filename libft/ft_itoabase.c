/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 20:30:23 by msales-a          #+#    #+#             */
/*   Updated: 2020/04/19 17:45:44 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t algnumbase(long number, unsigned int radix)
{
	size_t		algs;
	long long	num;

	if (!radix)
		return (0);
	if (!number)
		return(1);
	algs = 0;
	num = number < 0 ? -1 * number : number;
	while (num)
	{
		algs++;
		num /= radix;
	}
	return (algs);
}

char	*ft_itoabase(long number, char const *base)
{
	int			radix;
	int			index;
	char		*dst;
	long long	value;

	if (!base || !(radix = ft_strlen(base)))
		return (0);
	value = number < 0 ? -1 * number : number;
	index = algnumbase(number, radix) + (number < 0 ? 1 : 0);
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