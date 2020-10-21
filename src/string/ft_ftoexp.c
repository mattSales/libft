/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoexp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:45:50 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/21 20:24:04 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int		ft_get_mantissa(long double number)
{
	long double	value;
	int			index;

	value = (number < 0) ? number * -1 : number;
	index = 0;
	if (value == 0)
		return (index);
	while (value >= 10)
	{
		value /= 10;
		index++;
	}
	while (value < 1)
	{
		value *= 10;
		index--;
	}
	return (index);
}

char	*ft_format_mantissa(int mantissa)
{
	char *m;
	char *temp;

	m = ft_itoa(mantissa * ((mantissa < 0) ? -1 : 1));
	temp = ft_strjoin((mantissa < 10) ? "0" : "", m);
	free(m);
	if (mantissa >= 0)
		m = ft_strjoin("e+", temp);
	else
		m = ft_strjoin("e-", temp);
	free(temp);
	return (m);
}

char	*ft_ftoexp(long double number, int precision)
{
	int		mantissa;
	char	*mantissa_temp;
	char	*value_temp;
	char	*result;

	mantissa = ft_get_mantissa(number);
	mantissa_temp = ft_format_mantissa(mantissa);
	if (mantissa > 0)
		value_temp = ft_ftoa(number / ft_pow(10, mantissa), precision);
	else
	{
		mantissa *= -1;
		value_temp = ft_ftoa(number * ft_pow(10, mantissa), precision);
	}
	result = ft_strjoin(value_temp, mantissa_temp);
	free(mantissa_temp);
	free(value_temp);
	return (result);
}
