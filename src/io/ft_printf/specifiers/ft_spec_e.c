/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/20 16:17:41 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_e(t_print_op *op)
{
	long double n;

	if (op->length == plength_L)
		n = va_arg(*op->arguments, long double);
	else
		n = va_arg(*op->arguments, double);
	if (op->specifier == 'E')
		op->value = ft_ftoexp(n, op->precision, true);
	else
		op->value = ft_ftoexp(n, op->precision, false);
}
