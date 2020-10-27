/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 17:22:02 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/27 08:59:50 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xprintf(t_print_op *op)
{
	char	*temp;

	if (ft_printf_parser(op))
		ft_printf_specifier(op);
	else
		op->value = ft_repeatchr(op->specifier, 1);
	ft_printf_precision(op);
	ft_printf_width(op);
	ft_printf_flags(op);
	if (ft_strchr("FEGAX", op->specifier))
	{
		temp = ft_strtoupper(op->value);
		free(op->value);
		op->value = temp;
	}
	if (op->specifier != 'n')
	{
		ft_putstr_fd(op->value, 1);
		op->print_size += ft_strlen(op->value);
		free(op->value);
	}
	return (1);
}

int	ft_vprintf(const char *format, va_list *arguments)
{
	t_print_op op;

	if (!format || !arguments)
		return (0);
	op.format = format;
	op.arguments = arguments;
	op.print_size = 0;
	while (*op.format)
	{
		if (*op.format == '%')
		{
			ft_xprintf(&op);
			continue ;
		}
		ft_putchar_fd(*op.format, 1);
		op.format++;
		op.print_size++;
	}
	return (op.print_size);
}

int	ft_printf(const char *format, ...)
{
	va_list arguments;
	int		index;

	if (!format)
		return (0);
	va_start(arguments, format);
	index = ft_vprintf(format, &arguments);
	va_end(arguments);
	return (index);
}
