/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:22:11 by msales-a          #+#    #+#             */
/*   Updated: 2020/02/10 20:38:55 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		index;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	index = 0;
	while (s[index] && index < (int)len)
	{
		dest[index] = *(s + start + index);
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
