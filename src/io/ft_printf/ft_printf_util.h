/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:47:34 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/20 16:30:42 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTIL_H
# define FT_PRINTF_UTIL_H

# include "printf.h"

typedef struct	s_print_op
{
	int			config;
	int			width;
	int			precision;
	char		length;
	char		specifier;
	void		*value;
	char		*format;
	va_list		*arguments;
	long long	print_size;
}				t_print_op;

# define FLAG_PLUS 1
# define FLAG_MINUS 2
# define FLAG_SPACE 4
# define FLAG_ZERO 8
# define FLAG_HASHTAG 16
# define HAS_WIDTH 32
# define HAS_PRECISION 64

typedef enum	e_plength
{
	plength_none = 0,
	plength_hh = 1,
	plength_h = 2,
	plength_l = 4,
	plength_ll = 3,
	plength_j = 4,
	plength_z = 5,
	plength_t = 6,
	plength_L = 7,

}				t_plength;

#endif
