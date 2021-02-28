/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:12:50 by msales-a          #+#    #+#             */
/*   Updated: 2020/11/12 18:22:27 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strtoupper(char *str)
{
	char	*temp;
	int		index;

	index = ft_strlen(str);
	if (!(temp = malloc(sizeof(char) * (index + 1))))
		return (NULL);
	temp[index] = '\0';
	index = 0;
	while (str[index])
	{
		temp[index] = ft_toupper(str[index]);
		index++;
	}
	return (temp);
}
