/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 09:59:41 by msales-a          #+#    #+#             */
/*   Updated: 2020/11/12 18:22:07 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_nitoa(char size, int value)
{
	int		length;
	char	*result;

	length = ft_algs_num(value);
	if (length < size)
		length = size;
	if (!(result = malloc(sizeof(char) * (length + 2))))
		return (NULL);
	result[length + 1] = '\0';
	result[0] = (value < 0) ? '-' : '+';
	value *= (value < 0) ? -1 : 1;
	while (length)
	{
		result[length--] = value % 10 + '0';
		value /= 10;
	}
	return (result);
}
