/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repeatchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:08:45 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/18 23:11:03 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_repeatchr(char c, int times)
{
	char *result;

	result = ft_calloc(times + 1, sizeof(char));
	ft_memset(result, c, times);
	return (result);
}
