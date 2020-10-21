/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:14:26 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/21 19:18:35 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_parser(t_print_op *operation)
{
	operation->config = 0;
	operation->width = 0;
	operation->precision = 0;
	operation->specifier = 0;
	operation->value = NULL;
	if (*operation->format == '%')
		operation->format++;
	parse_flags(operation);
	parse_width(operation);
	parse_precision(operation);
	parse_length(operation);
	if (parse_specifier(operation))
		return (0);
	return (1);
}
