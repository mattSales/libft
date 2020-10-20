/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/20 09:07:26 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_di(t_print_op *op)
{
	if (op->length <= plength_h)
		op->value = ft_llitoa(va_arg(*op->arguments, int));
	else if (op->length <= plength_l)
		op->value = ft_llitoa(va_arg(*op->arguments, long int));
	else if (op->length <= plength_ll)
		op->value = ft_llitoa(va_arg(*op->arguments, long long int));
	else
		op->value = ft_ullitoa(va_arg(*op->arguments, size_t));
}
