/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/20 10:01:12 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_u(t_print_op *op)
{
	if (op->length <= plength_h)
		op->value = ft_ullitoa(va_arg(*op->arguments, unsigned int));
	else if (op->length <= plength_l)
		op->value = ft_ullitoa(va_arg(*op->arguments, unsigned long int));
	else if (op->length <= plength_ll)
		op->value = ft_ullitoa(va_arg(*op->arguments, unsigned long long int));
	else
		op->value = ft_ullitoa(va_arg(*op->arguments, size_t));
}
