/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 07:45:53 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/20 11:44:22 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_spec(t_print_op *op)
{
	void	(*f[127])();

	f['d' - 0] = ft_spec_di;
	f['i' - 0] = ft_spec_di;
	f['u' - 0] = ft_spec_u;
	f['o' - 0] = ft_spec_o;
	f['x' - 0] = ft_spec_x;
	f['X' - 0] = ft_spec_x;
	f['f' - 0] = ft_spec_f;
	f['F' - 0] = ft_spec_f;
	f['e' - 0] = ft_spec_e;
	f['F' - 0] = ft_spec_e;
	f['g' - 0] = ft_spec_g;
	f['G' - 0] = ft_spec_g;
	f['a' - 0] = ft_spec_a;
	f['A' - 0] = ft_spec_a;
	f['c' - 0] = ft_spec_c;
	f['s' - 0] = ft_spec_s;
	f['p' - 0] = ft_spec_p;
	f['n' - 0] = ft_spec_n;
	f['%' - 0] = ft_spec_per;
	f[op->specifier - 0]();
}
