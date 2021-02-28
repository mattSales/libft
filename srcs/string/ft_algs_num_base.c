/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algs_num_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 09:25:32 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/20 15:10:57 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int	ft_algs_num_base(long long number, unsigned int radix)
{
	unsigned int	algs;
	long long		num;

	if (!radix)
		return (0);
	if (!number)
		return (1);
	algs = 0;
	num = number < 0 ? -1 * number : number;
	while (num)
	{
		algs++;
		num /= radix;
	}
	return (algs);
}
