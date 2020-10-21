/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/21 20:24:48 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

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
		op->value = ft_ftoa(value, p - (x + 1));
	else if (op->specifier == 'G')
		op->value = ft_ftoexp(value, p - 1);
	else
		op->value = ft_ftoexp(value, p - 1);
}
