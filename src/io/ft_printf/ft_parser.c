/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:14:26 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/20 07:43:36 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print_op	*ft_parser(t_print_op *operation)
{
	operation->config = 0;
	operation->width = 0;
	operation->precision = 0;
	operation->specifier = 0;
	if (*operation->format == '%')
		operation->format++;
	parse_flags(operation);
	parse_width(operation);
	parse_precision(operation);
	parse_length(operation);
	if (parse_specifier(operation))
		return (NULL);
	return (operation);
}
