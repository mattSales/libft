/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:22:39 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/21 20:14:38 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/libft.h"
#include <stdio.h>

int		main()
{
	int n;
	int	*b;

	b = &n;

	ft_printf("d: <%50d>\n", 2147483647);
	ft_printf("i: <%0-50i>\n", 2147483647);
	ft_printf("u: <%*u>\n", 10, 2147483647);
	ft_printf("o: <%#o>\n", 2147483647);
	ft_printf("x: <%#x>\n", 2147483647);
	ft_printf("X: <%X>\n", 2147483647);
	ft_printf("f: <%.*f>\n", 2, 100.65625);
	ft_printf("F: <%F>\n", 100.65625);
	ft_printf("e: <%e>\n", -0.00000054321);
	ft_printf("E: <% E>\n", 0.00000054321);
	ft_printf("g: <%g>\n", 100.65625);
	ft_printf("G: <%G>\n", 0.00000054321);
	ft_printf("a: <%a>\n", 100.65625);
	ft_printf("A: <%A>\n", 33.);
	ft_printf("c: <%-5c>\n", 'c');
	ft_printf("s: <%.4s>\n", "TESTTTTTTT");
	ft_printf("p: <%20p>\n", b);
	printf("p: <%20p>\n", b);
	printf("n: <%n> <%d>\n", b, *b);
	ft_printf("%%: <%20%>\n");
	return (0);
}