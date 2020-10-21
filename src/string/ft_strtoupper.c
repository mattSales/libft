/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:12:50 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/21 16:15:51 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strtoupper(char *str)
{
	char	*temp;
	int		index;

	if (!(temp = malloc(sizeof(char) * ft_strlen(str))))
		return (NULL);
	index = 0;
	while (str[index])
	{
		temp[index] = ft_toupper(str[index]);
		index++;
	}
	return (temp);
}