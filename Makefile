# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 20:52:40 by msales-a          #+#    #+#              #
#    Updated: 2020/10/14 16:23:08 by msales-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

DIRECTORY = ./src/

HEADERS = $(shell find $(DIRECTORY) -name '*.h')

SOURCES = $(shell find $(DIRECTORY) -name '*.c')

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

test: all
	cd test && $(MAKE) re
