/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/20 10:05:39 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_x(t_print_op *op)
{
	char *base;

	if (op->specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (op->length <= plength_h)
		op->value = ft_ullitoabase(va_arg(*op->arguments, unsigned int), base);
	else if (op->length <= plength_l)
		op->value = ft_ullitoabase(va_arg(*op->arguments, unsigned long), base);
	else
		op->value = ft_ullitoabase(va_arg(*op->arguments, size_t), base);
}
