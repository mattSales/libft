/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 09:32:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/11/12 18:20:54 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

long long int	ft_ftoa_pvalue(double n, int p, int *s, int *l)
{
	long long int	value;

	value = n * ft_pow(10, p + 1);
	if ((value % 10 < -4) || (value % 10 > 4))
		value = ((value / 10) + ((value / 10) % 2));
	else
		value = (value / 10);
	*s = ft_hexfloat_signal(n);
	*l = ft_algs_num(value * ft_pow(10, p * -1)) + (p != 0) + p;
	return (value);
}

char			*ft_ftoa(double number, int precision)
{
	int				signal;
	long long int	value;
	int				length;
	char			*temp;

	precision = (precision < 0) ? 0 : precision;
	value = ft_abs(ft_ftoa_pvalue(number, precision, &signal, &length));
	if (!(temp = malloc(sizeof(char) * (signal + length + 1))))
		return (NULL);
	temp[0] = '-';
	temp[signal + length] = '\0';
	while (length--)
	{
		temp[signal + length] = value % 10 + '0';
		value /= 10;
		if (--precision == 0)
			temp[signal + --length] = '.';
	}
	return (temp);
}
