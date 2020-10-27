/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/24 21:12:08 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

int		ft_spec_g_precision(long double value, int precision)
{
	int			zeros;
	long long	n;

	if (precision <= 0)
		return (0);
	zeros = 0;
	n = (value - (int)value) * ft_pow(10, precision);
	n = (value < 0) ? value * -1 : value;
	while (n >= 10)
	{
		if (n%10 == 0)
			zeros++;
		n /= 10;
	}
	return (precision - zeros);
}

void	ft_spec_g(t_print_op *op)
{
	long double	value;
	int 		x;
	int 		p;

	if (op->length == plength_L)
		value = va_arg(*op->arguments, long double);
	else
		value = va_arg(*op->arguments, double);
	x = ft_get_mantissa(value);
	if (op->config & HAS_PRECISION)
		p = (op->precision != 0) ? op->precision : 1;
	else
		p = 6;
	if (p > x && x >= -4)
		op->value = ft_ftoa(value, ft_spec_g_precision(value, p - (x + 1)));
	else
		op->value = ft_ftoexp(value, ft_spec_g_precision(value, p - 1));
}
