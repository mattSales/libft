/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:43:37 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/21 17:16:37 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width_a(char *width, t_print_op *op)
{
	char	*temp;
	char	*result;

	temp = op->value + ((*op->value == '-') ? 3 : 2);
	temp = ft_strjoin(width, temp);
	if (op->specifier == 'a')
		result = ft_strjoin((*op->value == '-') ? "-0x" : "0x", temp);
	else
		result = ft_strjoin((*op->value == '-') ? "-0X" : "0X", temp);
	free(temp);
	return (result);
}

void	ft_printf_width(t_print_op *op)
{
	char	*width;
	char	*temp;

	if (op->config & HAS_WIDTH)
	{
		if (op->config & FLAG_ZERO && !(op->config & FLAG_MINUS))
			width = ft_repeatchr('0', op->width - ft_strlen(op->value));
		else
			width = ft_repeatchr(' ', op->width - ft_strlen(op->value));
		if (op->config & FLAG_MINUS)
			temp = ft_strjoin(op->value, width);
		else if (ft_strchr("aA", op->specifier) && width[0] == '0')
			temp = ft_width_a(width, op);
		else
			temp = ft_strjoin(width, op->value);
		free(width);
		free(op->value);
		op->value = temp;
	}
}
