/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:05:26 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 23:30:46 by msales-a         ###   ########.fr       */
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

static bool	ft_atof_has_digit(char *input)
{
	while (input && *input)
		if (ft_isdigit(*input++))
			return (true);
	return (false);
}

double	ft_atof(char *input)
{
	double	i;
	double	d;
	char	*temp;

	i = 0;
	ft_atof_edge_cases(input, &i);
	if (i != 0)
		return (i);
	if (!ft_atof_has_digit(input))
		return (0);
	i = ft_atoill(input);
	temp = ft_strchr(input, '.');
	if (!temp || *temp != '.')
		return (i);
	d = ft_atoill(temp + 1);
	d = d / ft_pow(10, ft_algs_num(d));
	if (!ft_isdigit(*(temp + 1)))
		d = 0;
	if (i < 0)
		d *= -1;
	return (i + d);
}
