/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 20:45:32 by msales-a          #+#    #+#             */
/*   Updated: 2020/04/21 07:55:00 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

typedef enum	e_length
{
	none = 0,
	hh,
	h,
	ll,
	l,
	j,
	z,
	t,
	L
}				t_length;

typedef struct	s_format
{
	char		flag;
	int			width;
	int			precision;
	t_length	length;
	char		specifier;
}				t_format;

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memccpy(void *dst, void const *src, int c, size_t n);
void			*ft_memcpy(void *dst, void const *src, size_t n);
void			*ft_memmove(void *dst, void const *src, size_t len);
void			*ft_memchr(void const *s, int c, size_t n);
int				ft_memcmp(void const *s1, void const *s2, size_t n);
size_t			ft_strlen(char const *s);
size_t			ft_strnlen(char const *s, size_t maxlen);
size_t			ft_strlcpy(char *dst, char const *src, size_t dstsize);
size_t			ft_strlcat(char *dst, char const *src, size_t dstsize);
char			*ft_strchr(char const *s, int c);
char			*ft_strrchr(char const *s, int c);
char			*ft_strnstr(char const *big, char const *little, size_t len);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
int				ft_isspace(int c);
int				ft_isdigit(int c);
int				ft_atoi(char const *str);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(char const *s1);
char			*ft_strndup(char const *s, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
int				ft_algs_num(long n);
char			*ft_itoa(int n);
char			*ft_itoabase(long number, char const *base);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(unsigned int c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *));

#endif
