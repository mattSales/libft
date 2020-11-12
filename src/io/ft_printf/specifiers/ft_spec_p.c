/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/28 15:27:39 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_p(t_print_op *op)
{
	char	*base;
	void	*ptr;

	base = "0123456789abcdef";
	op->v_prefix = ft_strdup("0x");
	if (!(ptr = va_arg(*op->arguments, void*)))
		op->v_value = ft_strdup("0");
	else
		op->v_value = ft_ullitoabase((unsigned long long int)ptr, base);
}
