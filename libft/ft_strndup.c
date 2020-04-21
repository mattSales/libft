/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:08:21 by msales-a          #+#    #+#             */
/*   Updated: 2020/04/19 17:43:38 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *s, size_t n)
{
	size_t	index;
	char	*dst;

	index = ft_strlen(s);
	index = (n < index) ? n : index;
	if (!(dst = (char*)ft_calloc((index + 1), sizeof(char))))
		return (0);
	ft_strlcpy(dst, s, index + 1);
	return (dst);
}
