# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 20:52:40 by msales-a          #+#    #+#              #
#    Updated: 2021/02/28 15:24:24 by msales-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

HEADERS = ./srcs/ctype/ctype.h \
          ./srcs/memory/memory.h \
          ./srcs/libft.h \
          ./srcs/io/ft_printf/ft_printf_util.h \
          ./srcs/io/ft_printf/ft_printf.h \
          ./srcs/io/ft_printf/specifiers/specifiers.h \
		  ./srcs/io/get_next_line/get_next_line.h \
          ./srcs/io/io.h \
          ./srcs/math/math.h \
          ./srcs/list/list.h \
          ./srcs/list/list_struct.h \
          ./srcs/string/string.h

SOURCES = ./srcs/ctype/ft_isdigit.c \
          ./srcs/ctype/ft_isascii.c \
          ./srcs/ctype/ft_isprint.c \
          ./srcs/ctype/ft_toupper.c \
          ./srcs/ctype/ft_isalpha.c \
          ./srcs/ctype/ft_islower.c \
          ./srcs/ctype/ft_isupper.c \
          ./srcs/ctype/ft_isalnum.c \
          ./srcs/ctype/ft_isspace.c \
          ./srcs/ctype/ft_tolower.c \
          ./srcs/memory/ft_memcmp.c \
          ./srcs/memory/ft_bzero.c \
          ./srcs/memory/ft_memcpy.c \
          ./srcs/memory/ft_memccpy.c \
          ./srcs/memory/ft_memchr.c \
          ./srcs/memory/ft_memset.c \
          ./srcs/memory/ft_memmove.c \
          ./srcs/memory/ft_calloc.c \
          ./srcs/io/ft_putstr_fd.c \
          ./srcs/io/ft_putnbr_fd.c \
          ./srcs/io/ft_putendl_fd.c \
          ./srcs/io/ft_printf/ft_printf_width.c \
          ./srcs/io/ft_printf/ft_parsers.c \
          ./srcs/io/ft_printf/ft_printf_parser.c \
          ./srcs/io/ft_printf/ft_printf.c \
          ./srcs/io/ft_printf/ft_printf_flags.c \
          ./srcs/io/ft_printf/ft_printf_specifier.c \
          ./srcs/io/ft_printf/ft_printf_precision.c \
          ./srcs/io/ft_printf/specifiers/ft_spec_e.c \
          ./srcs/io/ft_printf/specifiers/ft_spec_o.c \
          ./srcs/io/ft_printf/specifiers/ft_spec_a.c \
          ./srcs/io/ft_printf/specifiers/ft_spec_s.c \
          ./srcs/io/ft_printf/specifiers/ft_spec_f.c \
          ./srcs/io/ft_printf/specifiers/ft_spec_per.c \
          ./srcs/io/ft_printf/specifiers/ft_spec_p.c \
          ./srcs/io/ft_printf/specifiers/ft_spec_g.c \
          ./srcs/io/ft_printf/specifiers/ft_spec_c.c \
          ./srcs/io/ft_printf/specifiers/ft_spec_u.c \
          ./srcs/io/ft_printf/specifiers/ft_spec_n.c \
          ./srcs/io/ft_printf/specifiers/ft_spec_di.c \
          ./srcs/io/ft_printf/specifiers/ft_spec_x.c \
		  ./srcs/io/get_next_line/get_next_line.c \
          ./srcs/io/ft_putchar_fd.c \
          ./srcs/math/ft_pow.c \
          ./srcs/math/ft_abs.c \
          ./srcs/list/ft_lstadd_back.c \
          ./srcs/list/ft_lstnew.c \
          ./srcs/list/ft_lstlast.c \
          ./srcs/list/ft_lstclear.c \
          ./srcs/list/ft_lstiter.c \
          ./srcs/list/ft_lstmap.c \
          ./srcs/list/ft_lstsize.c \
          ./srcs/list/ft_lstadd_front.c \
          ./srcs/list/ft_lstdelone.c \
          ./srcs/string/ft_strnstr.c \
          ./srcs/string/ft_ftoa.c \
          ./srcs/string/ft_llitoa.c \
          ./srcs/string/ft_algs_num_base.c \
          ./srcs/string/ft_strlcpy.c \
          ./srcs/string/ft_strlen.c \
          ./srcs/string/ft_strnlen.c \
          ./srcs/string/ft_strchr.c \
          ./srcs/string/ft_strjoin.c \
          ./srcs/string/ft_split.c \
          ./srcs/string/ft_ullitoa.c \
          ./srcs/string/ft_strrchr.c \
          ./srcs/string/ft_ullitoabase.c \
          ./srcs/string/ft_substr.c \
          ./srcs/string/ft_strncmp.c \
          ./srcs/string/ft_stdfloat.c \
          ./srcs/string/ft_algs_num.c \
          ./srcs/string/ft_strmapi.c \
          ./srcs/string/ft_strtrim.c \
          ./srcs/string/ft_strndup.c \
          ./srcs/string/ft_repeatchr.c \
          ./srcs/string/ft_strlcat.c \
          ./srcs/string/ft_strdup.c \
          ./srcs/string/ft_nitoa.c \
          ./srcs/string/ft_strtoupper.c \
          ./srcs/string/ft_itoabase.c \
          ./srcs/string/ft_llitoabase.c \
          ./srcs/string/ft_hexfloat.c \
          ./srcs/string/ft_atoi.c \
          ./srcs/string/ft_itoa.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS) $(HEADERS)
	@ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	@gcc -Wall -Wextra -Werror -g -c $< -o $@

clean :
	@rm -f $(OBJECTS)

fclean :
	@rm -f $(NAME)

re : all clean

bonus: all
