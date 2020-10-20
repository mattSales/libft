/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 09:32:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/20 15:35:34 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_ftoa(long double number, int precision)
{
	long long	value;
	size_t		length;
	char		*result;

	precision = (precision < 0) ? 0 : precision;
	value = (long long)(number * ft_pow(10, precision + 1));
	value = (value / 10) + (value % 10 >= 5);
	length = (number < 0) + (precision != 0) + ft_algs_num(value) + 1;
	if (!(result = malloc(sizeof(char) * length)))
		return (NULL);
	result[0] = '-';
	result[--length] = '\0';
	while (value)
	{
		result[--length] = value % 10 + '0';
		value /= 10;
		if (--precision == 0)
			result[--length] = '.';
	}
	return (result);
}
