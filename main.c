/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:22:39 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/21 12:58:03 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/libft.h"
#include <stdio.h>

void print_raw_double_binary(double d)
{
 unsigned long long *double_as_int = (unsigned long long *)&d;
 int i;
 for (i=0; i<=63; i++)
   {

    if (i==1)
      printf(" "); // Space after sign field
    if (i==12)
      printf(" "); // Space after exponent field

    if ((*double_as_int >> (63-i)) & 1)
      printf("1");
    else
      printf("0");
   }
 printf("\n");
}

void parse_double(double d, unsigned char *sign_field, unsigned short *exponent_field, unsigned long long *fraction_field)
{
	unsigned long long *double_as_int = (unsigned long long *)&d;

	*sign_field = (unsigned char)(*double_as_int >> 63);
	*exponent_field = (unsigned short)(*double_as_int >> 52 & 0x7FF);
	*fraction_field = *double_as_int & 0x000FFFFFFFFFFFFFULL;
}

void print_raw_double_hex(double d)
{
	unsigned char sign_field;
	unsigned short exponent_field;
	unsigned long long fraction_field;

	parse_double(d,&sign_field,&exponent_field,&fraction_field);

	printf("%x %x %llx\n",sign_field,exponent_field,fraction_field);
}

void	perff(char *format, ...)
{
	va_list		arguments;
	t_print_op	op;

	va_start(arguments, format);
	op.format = format;
	op.arguments = &arguments;
	ft_parser(&op);
	ft_spec(&op);
	printf("%s\n", op.value);
	va_end(arguments);
}

void	*ft_format_mantissa2(unsigned long long int *n, int l, int p)
{
	unsigned char	*m;
	char	*r;
	int		index;

	if (!(m = ft_calloc(((p > l) ? p : l) + 2, sizeof(unsigned char))))
		return (NULL);
	index = -1;
	m[0] = 1;
	while (index++ < l - 1)
		m[l - index] = (*n >> (4 * index)) & 0xf;
	if (m[p + 1] >= 8)
		m[p]++;
	if (!(r = ft_calloc(((p > 0) ? p + 3 : 2), sizeof(unsigned char))))
		return (NULL);
	r[0] = "0123456789abcdef"[m[0]];
	r[1] = (p > 0) ? '.' : '\0';
	index = p + 1;
	while (--index)
		r[index + 1] = "0123456789abcdef"[m[index]];
	return (r);
}

int		main()
{
	double	k;
	unsigned long long	*n;
	unsigned char		signal;
	unsigned long		exponent;
	unsigned long long	fraction;
	int					index;

	k = 8.;
	n= (unsigned long long *)&k;
	signal = (unsigned char)(*n >> 63) & 1;
	exponent = (unsigned long)(*n >> 52 & 0x7ff);
	fraction = *n & 0x000FFFFFFFFFFFFFULL;
	index = 0;
	while (!((*n >> (64 - 1 - 11 - 1 - index)) & 1) && index < 52)
		index++;
	printf("a: %.1a\n", k);
	printf("double: %f\n", k);
	printf("signal: %u\n", signal);
	printf("exponent: %ld\n", exponent);
	printf("exponent - bias: %ld\n", exponent - 1023);
	printf("fraction: %lld\n", fraction);
	printf("fraction (hex): %s\n", ft_ullitoabase(fraction, "0123456789abcdef"));
	printf("zeros at the beginning: %d\n", index);
	printf("bits:");
	print_raw_double_binary(k);
	printf("%s\n", ft_hfptoa(k, 1));
	return (0);
}

//0001 1111 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
//   1    f    0    0    0    0    0    0    0    0    0    0    0