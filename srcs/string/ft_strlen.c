/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:33:46 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/28 21:05:37 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

size_t	ft_strlen(char const *s)
{
	size_t index;

	index = 0;
	while (s && s[index])
		index++;
	return (index);
}
