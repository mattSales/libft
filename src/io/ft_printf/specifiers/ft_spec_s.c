/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:48:44 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/27 07:36:52 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifiers.h"

void	ft_spec_s(t_print_op *op)
{
	char	*ptr;

	ptr = va_arg(*op->arguments, char*);
	if (ptr)
		op->value = ft_strdup(ptr);
	else
		op->value = ft_strdup("(null)");
}
