/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 07:45:53 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/21 19:23:09 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_flags_plus_space(t_print_op *op)
{
	char	*temp;

	if (!ft_strchr("cspn%%", op->specifier))
	{
		if (*op->value != '-')
		{
			if (op->config & FLAG_PLUS)
				temp = ft_strjoin("+", op->value);
			else
				temp = ft_strjoin(" ", op->value);
			free(op->value);
			op->value = temp;
		}
	}
}

void	ft_printf_flags_hashtag_base(t_print_op *op)
{
	char	*temp;

	if (ft_strchr("oxX", op->specifier))
	{
		if (op->specifier == 'o')
			temp = ft_strjoin("0", op->value);
		if (op->specifier == 'x')
			temp = ft_strjoin("0x", op->value);
		if (op->specifier == 'X')
			temp = ft_strjoin("0X", op->value);
		free(op->value);
		op->value = temp;
	}
}

void	ft_printf_flags_hashtag_dot_f(t_print_op *op)
{
	char	*temp;

	if (ft_strchr("fF", op->specifier) && !ft_strchr(op->value, '.'))
	{
		temp = ft_strjoin(op->value, ".");
		free(op->value);
		op->value = temp;
	}
}

int		ft_printf_flags_hashtag_dot_aeg(t_print_op *op)
{
	char	*ptr;
	char	*temp;
	char	*result;
	int		index;

	if (ft_strchr(op->value, '.') || !ft_strchr("aAeEgG", op->specifier))
		return (0);
	ptr = NULL;
	index = 0;
	while ("pPeE"[index] && !ptr)
		ptr = ft_strchr(op->value, "pPeE"[index++]);
	if (!ptr)
		ptr = ft_strchr(op->value, '\0');
	temp = ft_substr(op->value, 0, ptr - op->value);
	result = ft_strjoin(temp, ".");
	ptr = ft_strjoin(result, ptr);
	free(op->value);
	free(temp);
	op->value = ptr;
	return (0);
}

void	ft_printf_flags(t_print_op *op)
{
	if (op->config & FLAG_PLUS || op->config & FLAG_SPACE)
		ft_printf_flags_plus_space(op);
	if (op->config & FLAG_HASHTAG)
	{
		ft_printf_flags_hashtag_base(op);
		ft_printf_flags_hashtag_dot_f(op);
		ft_printf_flags_hashtag_dot_aeg(op);
	}
}
