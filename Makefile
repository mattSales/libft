# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 20:52:40 by msales-a          #+#    #+#              #
#    Updated: 2020/11/21 09:51:45 by msales-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

HEADERS = ./src/ctype/ctype.h \
          ./src/memory/memory.h \
          ./src/libft.h \
          ./src/io/ft_printf/ft_printf_util.h \
          ./src/io/ft_printf/ft_printf.h \
          ./src/io/ft_printf/specifiers/specifiers.h \
          ./src/io/io.h \
          ./src/math/math.h \
          ./src/list/list.h \
          ./src/list/list_struct.h \
          ./src/string/string.h

SOURCES = ./src/ctype/ft_isdigit.c \
          ./src/ctype/ft_isascii.c \
          ./src/ctype/ft_isprint.c \
          ./src/ctype/ft_toupper.c \
          ./src/ctype/ft_isalpha.c \
          ./src/ctype/ft_islower.c \
          ./src/ctype/ft_isupper.c \
          ./src/ctype/ft_isalnum.c \
          ./src/ctype/ft_isspace.c \
          ./src/ctype/ft_tolower.c \
          ./src/memory/ft_memcmp.c \
          ./src/memory/ft_bzero.c \
          ./src/memory/ft_memcpy.c \
          ./src/memory/ft_memccpy.c \
          ./src/memory/ft_memchr.c \
          ./src/memory/ft_memset.c \
          ./src/memory/ft_memmove.c \
          ./src/memory/ft_calloc.c \
          ./src/io/ft_putstr_fd.c \
          ./src/io/ft_putnbr_fd.c \
          ./src/io/ft_putendl_fd.c \
          ./src/io/ft_printf/ft_printf_width.c \
          ./src/io/ft_printf/ft_parsers.c \
          ./src/io/ft_printf/ft_printf_parser.c \
          ./src/io/ft_printf/ft_printf.c \
          ./src/io/ft_printf/ft_printf_flags.c \
          ./src/io/ft_printf/ft_printf_specifier.c \
          ./src/io/ft_printf/ft_printf_precision.c \
          ./src/io/ft_printf/specifiers/ft_spec_e.c \
          ./src/io/ft_printf/specifiers/ft_spec_o.c \
          ./src/io/ft_printf/specifiers/ft_spec_a.c \
          ./src/io/ft_printf/specifiers/ft_spec_s.c \
          ./src/io/ft_printf/specifiers/ft_spec_f.c \
          ./src/io/ft_printf/specifiers/ft_spec_per.c \
          ./src/io/ft_printf/specifiers/ft_spec_p.c \
          ./src/io/ft_printf/specifiers/ft_spec_g.c \
          ./src/io/ft_printf/specifiers/ft_spec_c.c \
          ./src/io/ft_printf/specifiers/ft_spec_u.c \
          ./src/io/ft_printf/specifiers/ft_spec_n.c \
          ./src/io/ft_printf/specifiers/ft_spec_di.c \
          ./src/io/ft_printf/specifiers/ft_spec_x.c \
          ./src/io/ft_putchar_fd.c \
          ./src/math/ft_pow.c \
          ./src/math/ft_abs.c \
          ./src/list/ft_lstadd_back.c \
          ./src/list/ft_lstnew.c \
          ./src/list/ft_lstlast.c \
          ./src/list/ft_lstclear.c \
          ./src/list/ft_lstiter.c \
          ./src/list/ft_lstmap.c \
          ./src/list/ft_lstsize.c \
          ./src/list/ft_lstadd_front.c \
          ./src/list/ft_lstdelone.c \
          ./src/string/ft_strnstr.c \
          ./src/string/ft_ftoa.c \
          ./src/string/ft_llitoa.c \
          ./src/string/ft_algs_num_base.c \
          ./src/string/ft_strlcpy.c \
          ./src/string/ft_strlen.c \
          ./src/string/ft_strnlen.c \
          ./src/string/ft_strchr.c \
          ./src/string/ft_strjoin.c \
          ./src/string/ft_split.c \
          ./src/string/ft_ullitoa.c \
          ./src/string/ft_strrchr.c \
          ./src/string/ft_ullitoabase.c \
          ./src/string/ft_substr.c \
          ./src/string/ft_strncmp.c \
          ./src/string/ft_stdfloat.c \
          ./src/string/ft_algs_num.c \
          ./src/string/ft_strmapi.c \
          ./src/string/ft_strtrim.c \
          ./src/string/ft_strndup.c \
          ./src/string/ft_repeatchr.c \
          ./src/string/ft_strlcat.c \
          ./src/string/ft_strdup.c \
          ./src/string/ft_nitoa.c \
          ./src/string/ft_strtoupper.c \
          ./src/string/ft_itoabase.c \
          ./src/string/ft_llitoabase.c \
          ./src/string/ft_hexfloat.c \
          ./src/string/ft_atoi.c \
          ./src/string/ft_itoa.c

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
