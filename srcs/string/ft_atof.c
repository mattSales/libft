/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:05:26 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 23:44:24 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static void	ft_atof_edge_cases(char *input, double *output)
{
	char	*upper;
	char	*trim;
	int		len;

	upper = ft_strtoupper(input);
	trim = ft_strtrim(upper, " \t\r");
	len = ft_strlen(trim);
	if (!ft_strncmp("-INF", trim, len + 4))
		*output = -1. / 0.;
	if (!ft_strncmp("INF", trim, len + 3))
		*output = 1. / 0.;
	if (!ft_strncmp("+INF", trim, len + 4))
		*output = 1. / 0.;
	if (!ft_strncmp("NAN", trim, len + 3))
		*output = 0. / 0.;
	free(upper);
	free(trim);
}

double	ft_atof(char *input)
{
	double	i;
	double	d;
	char	*temp;
	int		s;

	i = 0;
	ft_atof_edge_cases(input, &i);
	if (i != 0)
		return (i);
	s = 1;
	if (*input == '-')
		s = -1;
	i = ft_atoill(input + (*input == '-'));
	temp = ft_strchr(input, '.');
	if (!temp || *temp != '.')
		return (s * i);
	d = ft_atoill(temp + 1);
	if (d)
		d /= ft_pow(10, ft_algs_num(d));
	return (s * (i + d));
}
