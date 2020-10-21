/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:43:37 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/21 17:12:59 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_precision_diuox(t_print_op *op)
{
	char	*width;
	char	*temp;

	width = ft_repeatchr('0', op->precision - ft_strlen(op->value));
	temp = ft_strjoin(width, op->value);
	free(op->value);
	free(width);
	op->value = temp;
}

void	ft_printf_precision_s(t_print_op *op)
{
	char	*temp;

	temp = ft_substr(op->value, 0, op->precision);
	free(op->value);
	op->value = temp;
}

void	ft_printf_precision(t_print_op *op)
{
	if (op->config & HAS_PRECISION)
	{
		if (ft_strchr("diuoxX", op->specifier))
			ft_printf_precision_diuox(op);
		else if (op->specifier == 's')
			ft_printf_precision_s(op);
	}
}
