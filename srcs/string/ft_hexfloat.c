/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:43:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/11/21 14:24:57 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int		ft_hexfloat_signal(double number)
{
	unsigned long long	*n;

	n = (unsigned long long *)&number;
	return (*n >> 63 & 1);
}

int		ft_hexfloat_precision(double number)
{
	unsigned long long int	*a;
	unsigned long long int	b;
	int						index;

	a = (unsigned long long int*)&number;
	b = *a & 0x000fffffffffffff;
	index = -1;
	while (index++ < 13 - 1)
	{
		if ((b >> (4 * index)) & 0xf)
			break ;
	}
	return (13 - index);
}

int		ft_hexfloat_exp(double number)
{
	unsigned long long	*n;
	int					exp;

	n = (unsigned long long *)&number;
	exp = (long)(*n >> 52 & 0x7ff) - 1023;
	return (exp);
}

char	*ft_hexfloat_mantissa_(unsigned long long int n, int p)
{
	unsigned char	*m;
	char			*r;
	int				index;

	if (!(m = ft_calloc(((p > 13) ? p : 13) + 2, sizeof(unsigned char))))
		return (NULL);
	index = -1;
	m[0] = 1;
	while (index++ < 12)
		m[13 - index] = (n >> (4 * index)) & 0xf;
	if (m[p + 1] >= 8)
		m[p]++;
	if (!(r = ft_calloc(((p > 0) ? p + 3 : 2), sizeof(unsigned char))))
		return (NULL);
	r[0] = "0123456789abcdef"[m[0]];
	r[1] = (p > 0) ? '.' : '\0';
	index = p + 1;
	while (--index)
		r[index + 1] = "0123456789abcdef"[m[index]];
	return (r);
}

char	*ft_hexfloat_mantissa(double number, int precision)
{
	unsigned long long int	*n;
	unsigned long long int	mantissa;

	n = (unsigned long long int*)&number;
	mantissa = *n & 0x000FFFFFFFFFFFFF;
	if (number == 0. / 0.)
		return (ft_strdup("nan"));
	if (number == -1. / 0.)
		return (ft_strdup("-inf"));
	if (number == 1. / 0.)
		return (ft_strdup("inf"));
	return (ft_hexfloat_mantissa_(mantissa, precision));
}
