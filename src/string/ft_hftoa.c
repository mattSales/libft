/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hftoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:43:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/21 12:58:28 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_hfp_exponent(unsigned long exponent)
{
	char	*temp;
	char	*result;
	
	temp = ft_llitoa(exponent);
	if (exponent >= 0)
		result = ft_strjoin("p+", temp);
	else
		result = ft_strjoin("p", temp);
	free(temp);
	return (result);
}

char	*ft_hfp_mantissa(unsigned long long int n, int l, int p)
{
	unsigned char	*m;
	char	*r;
	int		index;

	if (!(m = ft_calloc(((p > l) ? p : l) + 2, sizeof(unsigned char))))
		return (NULL);
	index = -1;
	m[0] = 1;
	while (index++ < l - 1)
		m[l - index] = (n >> (4 * index)) & 0xf;
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

char	*ft_hfptoa(double number, int precision)
{
	unsigned long long	*n;
	char				*exp;
	char				*mantissa;
	char				*temp;
	char				*result;

	n = (unsigned long long *)&number;
	exp = ft_hfp_exponent((unsigned long)(*n >> 52 & 0x7ff) - 1023);
	mantissa = ft_hfp_mantissa(*n & 0x000FFFFFFFFFFFFF, 13, precision);
	temp = ft_strjoin(mantissa, exp);
	result = ft_strjoin(((int)(*n >> 63) & 1) ? "-0x" : "0x", temp);
	free(temp);
	free(mantissa);
	free(exp);
	return (result);
}