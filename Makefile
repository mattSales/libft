# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/20 19:22:35 by msales-a          #+#    #+#              #
#    Updated: 2020/04/20 23:08:29 by msales-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft/

LIBFT = libft.a

SOURCE_DIR = src/

SOURCE = main.c

OBJECTS = $(SOURCE:.c=.o)

all: $(NAME)

$(addprefix $(LIBFT_DIR), $(LIBFT)):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME):
	@gcc -Wall -Wextra -Werror -c -g $(SOURCE)
	@gcc $(OBJECTS) $(addprefix $(LIBFT_DIR), $(LIBFT))