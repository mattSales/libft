/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:43:37 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/22 19:14:50 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width_generate(t_print_op *op)
{
	int	length;

	if (!(op->config & FLAG_ZERO) || op->config & FLAG_MINUS)
		return (ft_repeatchr(' ', op->width - ft_strlen(op->value)));
	if (ft_strchr("diuoxX", op->specifier) && op->config & HAS_PRECISION)
		return (ft_repeatchr(' ', op->width - ft_strlen(op->value)));
	length = op->width - ft_strlen(op->value);
	return (ft_repeatchr('0', length));
}

void	ft_width_suffix_a(char *width, t_print_op *op)
{
	char	*temp;
	char	*result;

	temp = op->value + ((*op->value == '-') ? 3 : 2);
	temp = ft_strjoin(width, temp);
	result = ft_strjoin((*op->value == '-') ? "-0x" : "0x", temp);
	free(temp);
	free(op->value);
	op->value = result;
}

void	ft_width_suffix_m(char *width, t_print_op *op)
{
	char	*temp;

	*op->value = '0';
	temp = ft_strjoin(width, op->value);
	*temp = '-';
	free(op->value);
	op->value = temp;
}

void	ft_width_suffix(char *width, t_print_op *op)
{
	char	*temp;

	if (op->config & FLAG_MINUS)
		temp = ft_strjoin(op->value, width);
	else
		temp = ft_strjoin(width, op->value);
	free(op->value);
	op->value = temp;
}

void	ft_printf_width(t_print_op *op)
{
	char	*width;

	if (op->config & HAS_WIDTH)
	{
		width = ft_width_generate(op);
		if (ft_strchr("aA", op->specifier) && *width == '0')
			ft_width_suffix_a(width, op);
		else if (*op->value == '-' && *width == '0')
			ft_width_suffix_m(width, op);
		else
			ft_width_suffix(width, op);
		free(width);
	}
}
