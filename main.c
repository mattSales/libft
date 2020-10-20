/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:22:39 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/20 16:22:41 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/libft.h"
#include <stdio.h>

void	perff(char *format, ...)
{
	va_list		arguments;
	t_print_op	op;

	va_start(arguments, format);
	op.format = format;
	op.arguments = &arguments;
	ft_parser(&op);
	ft_spec(&op);
	printf("%s\n", op.value);
	va_end(arguments);
}

int		main()
{
	double k;

	k = 3122.55;
	perff("%g", k);
	printf("%f \n", k);
	printf("%e \n", k);
	printf("%g \n", k);
	return (0);
}