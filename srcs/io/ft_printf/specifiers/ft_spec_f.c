/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/11/21 15:01:17 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_f(t_print_op *op)
{
	long double value;
	size_t		length;
	int			p;

	if (op->length == plength_L)
		value = va_arg(*op->arguments, long double);
	else
		value = va_arg(*op->arguments, double);
	p = (op->config & HAS_PRECISION) ? op->precision : 6;
	op->v_value = ft_stdfloat_limits(value);
	if (!op->v_value)
	{
		op->v_value = ft_ftoa(value, p);
		if (*op->v_value == '-')
		{
			op->v_signal = ft_strdup("-");
			length = ft_strlen(op->v_value + 1) + 1;
			ft_memmove(op->v_value, op->v_value + 1, length);
		}
	}
}
