/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/21 20:11:03 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

int	ft_spec_a_p(double number)
{
	unsigned long long int	*a;
	unsigned long long int	b;
	int						index;

	a = (unsigned long long int*)&number;
	b = *a & 0x000fffffffffffff;
	index = -1;
	while (index++ < 13 - 1)
	{
		if ((b >> (4 * index)) & 0xf)
			break ;
	}
	return (13 - index);
}

void	ft_spec_a(t_print_op *op)
{
	double	value;
	int		p;
	char	*temp;

	value = va_arg(*op->arguments, double);
	p = (op->config & HAS_PRECISION) ? op->precision : ft_spec_a_p(value);
	temp = ft_hfptoa(value, p);
	if (op->specifier == 'a')
		op->value = temp;
	else
	{
		op->value = ft_strtoupper(temp);
		free(temp);
	}
}
