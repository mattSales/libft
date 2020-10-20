/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 09:32:56 by msales-a          #+#    #+#             */
/*   Updated: 2020/10/20 15:56:58 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include "../libft.h"

# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>

size_t	ft_strlen(char const *s);
size_t	ft_strnlen(char const *s, size_t maxlen);
size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char const *src, size_t dstsize);
char	*ft_strchr(char const *s, int c);
char	*ft_strrchr(char const *s, int c);
char	*ft_strnstr(char const *big, char const *little, size_t len);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		ft_atoi(char const *str);
char	*ft_strdup(char const *s1);
char	*ft_strndup(char const *s, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_algs_num(long long n);
int		ft_algs_num_base(long long number, unsigned int radix);
char	*ft_repeatchr(char c, int times);
int		ft_get_mantissa(long double number);
char	*ft_ftoexp(long double number, int precision, bool upper);
char	*ft_itoa(int n);
char	*ft_ftoa(long double number, int precision);
char	*ft_llitoa(long long n);
char	*ft_ullitoa(unsigned long long n);
char	*ft_itoabase(int number, char const *base);
char	*ft_llitoabase(long long number, char const *base);
char	*ft_ullitoabase(unsigned long long number, char const *base);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
