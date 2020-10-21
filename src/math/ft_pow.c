/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:24:35 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/19 08:14:12 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

double	ft_pow(double x, double y)
{
	long double n;

	if (y < 0)
		return (0);
	n = 1;
	while (y--)
		n *= x;
	return (n);
}