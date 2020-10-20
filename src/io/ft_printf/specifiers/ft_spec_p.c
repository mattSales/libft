/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/20 10:15:16 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_p(t_print_op *op)
{
	char	*base;
	void	*ptr;
	char	*temp;

	base = "0123456789abcdef";
	ptr = va_arg(*op->arguments, void*);
	temp = ft_ullitoabase((unsigned long long int)ptr, base);
	op->value = ft_strjoin("0x", temp);
	free(temp);
}
