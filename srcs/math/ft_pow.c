/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:24:35 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 21:17:30 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

double	ft_pow(double x, double y)
{
	long double	n;

	n = 1;
	if (y < 0)
	{
		while (y++ < 0)
			n /= 10;
	}
	else
	{
		while (y--)
			n *= x;
	}
	return (n);
}
