# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 20:52:40 by msales-a          #+#    #+#              #
#    Updated: 2020/04/19 17:51:02 by msales-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

HEADERS = libft.h

PART1 = ft_memset.c \
	    ft_bzero.c \
	    ft_memccpy.c \
	    ft_memcpy.c \
	    ft_memmove.c \
	    ft_memchr.c \
	    ft_memcmp.c \
	    ft_strlen.c \
	    ft_strnlen.c \
	    ft_strlcpy.c \
	    ft_strlcat.c \
	    ft_strchr.c \
	    ft_strrchr.c \
	    ft_strnstr.c \
	    ft_strncmp.c \
	    ft_isspace.c \
	    ft_isdigit.c \
	    ft_atoi.c \
	    ft_isalpha.c \
	    ft_isalnum.c \
	    ft_isascii.c \
	    ft_isprint.c \
	    ft_toupper.c \
	    ft_tolower.c \
	    ft_calloc.c \
	    ft_strdup.c \
	    ft_strndup.c \

PART2 = ft_substr.c \
	    ft_strjoin.c \
	    ft_strtrim.c \
	    ft_split.c \
	    ft_algs_num.c \
	    ft_itoa.c \
		ft_itoabase.c \
	    ft_strmapi.c \
	    ft_putchar_fd.c \
	    ft_putstr_fd.c \
	    ft_putendl_fd.c \
	    ft_putnbr_fd.c

BONUS = ft_lstnew.c \
	    ft_lstadd_front.c \
	    ft_lstsize.c \
	    ft_lstlast.c \
	    ft_lstadd_back.c \
	    ft_lstdelone.c \
	    ft_lstiter.c \
	    ft_lstclear.c \
	    ft_lstmap.c
 
PART1OBJ = $(PART1:.c=.o)

PART2OBJ = $(PART2:.c=.o)

BONUSOBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME) : $(PART1OBJ) $(PART2OBJ) $(HEADERS)
	@gcc -Wall -Wextra -Werror -c $(PART1) $(PART2)
	@ar rcs $(NAME) $(PART1OBJ) $(PART2OBJ)

clean : 
	@rm -f $(PART1OBJ) $(PART2OBJ) $(BONUSOBJ)

fclean :
	@rm -f $(NAME)

re : all clean

bonus : $(PART1OBJ) $(PART2OBJ) $(BONUSOBJ)
	@gcc -Wall -Wextra -Werror -c $(PART1) $(PART2) $(BONUS)
	@ar rcs $(NAME) $(PART1OBJ) $(PART2OBJ) $(BONUSOBJ)