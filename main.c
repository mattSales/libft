/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 19:19:21 by msales-a          #+#    #+#             */
/*   Updated: 2020/04/21 07:56:05 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

t_format *format_parser_specifier(t_format *format, char *str)
{
	char *specifiers = "diuoxXfFeEgGaAcspn%%";
	char *specifier = ft_strchr(specifiers, *str);
	if (!specifier)
		return (0);
	format->specifier = *specifier;
	return (format);
}

t_format *format_parser_length(t_format *format, char *str)
{
	char	**lengths;
	size_t	length;
	int		index;

	index = 0;
	format->length = none;
	lengths = (char*[9]){"hh", "h", "ll", "l", "j", "z", "t", "L", ""};
	while (*lengths[index])
	{
		length = ft_strlen(lengths[index]);
		if (!ft_strncmp(str, lengths[index], length))
		{
			format->length = index + 1;
			str = str + length;
			break;
		}
		index++;
	}
	return (format_parser_specifier(format, str));
}

t_format *format_parser_precision(t_format *format, char *str)
{
	if (*str == '.')
	{
		str++;
		format->precision = ft_atoi(str);
		str = str + ft_algs_num(format->precision);
	}
	return (format_parser_length(format, str));
}

t_format *format_parser_width(t_format *format, char *str)
{
	if (*str == '*' || ft_isdigit(*str))
	{ 
		format->width = *str == '*' ? -1 : ft_atoi(str);
		str++;
	}
	return (format_parser_precision(format, str));
}

t_format *format_parser_flag(t_format *format, char *str)
{
	if (ft_strchr("-+ #0", *str))
		format->flag = *str++;
	return (format_parser_width(format, str));
}

t_format *format_reset(t_format *format)
{
	if (!format)
		return (0);
	format->flag = '\0';
	format->width = 0;
	format->precision = 0;
	format->length = none;
	format->specifier = '\0';
	return (format);
}

t_format *parser(t_format *format, char *str, va_list arg)
{
	if (!str)
		return (0);
	if (!format)
		return (0);
	format_reset(format);
	if (!(format_parser_flag(format, str)))
		return (0);
	if (format->width == -1)
		format->width = va_arg(arg, int);
	return (format);
}

void simulador(char *str, ...)
{
	t_format	format;
	va_list		args;

	va_start(args, str);
	parser(&format, str, args);
	printf("%%[flags][width][.precision][length]specifier\n");
	printf("<%c> <%d> <%d> <%d> <%c>\n", format.flag, format.width, format.precision, format.length, format.specifier);
	va_end(args);
}

bool format_check_length(t_format *format)
{
	char s;
	t_length length;
	
	s = format->specifier;
	length = format->length;
	if (!ft_strchr("diuoxXn", s) && length < L)
		return (true);
	if (!ft_strchr("fFeEgGaA", s) && (length == none || length == L))
		return (true);
	if ((s == 'c' || s == 's') && (length == none || length == l))
		return (true);
	if (s == 'p' && length == none)
		return (true);
	return (false);
}

int main()
{
	
	simulador("+*.3Le", 42);
	return (0);
}