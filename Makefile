# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 17:28:56 by msales-a          #+#    #+#              #
#    Updated: 2021/03/03 22:21:49 by msales-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a

SOURCE_DIRECTORY	:= srcs
TARGET_DIRECTORY	:= target

HEADER_FILES	:= $(filter %.h, $(shell find $(SOURCE_DIRECTORY) -type f))
SOURCE_FILES	:= $(filter %.c, $(shell find $(SOURCE_DIRECTORY) -type f))
OBJECT_FILES	:= $(subst $(SOURCE_DIRECTORY)/,/, $(SOURCE_FILES:.c=.o))
OBJECT_WITH_DIR	:= $(addprefix $(TARGET_DIRECTORY), $(OBJECT_FILES))

COMPILER		:= gcc
COMPILER_FLAGS	:= -Wall -Wextra -Werror

ARCHIVE			:= ar
ARCHIVE_FLAGS	:= -rcs

.PHONY : all clean fclean make re bonus
.SILENT : all clean fclean make re bonus

all : $(NAME)

$(NAME) : $(OBJECT_WITH_DIR) $(HEADER_FILES)
	@$(ARCHIVE) $(ARCHIVE_FLAGS) $(NAME) $(OBJECT_WITH_DIR)

$(TARGET_DIRECTORY)/%.o : $(SOURCE_DIRECTORY)/%.c
	@mkdir -p $(@D)
	@$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

clean :
	@rm -rf $(TARGET_DIRECTORY)

fclean :
	@rm -f $(NAME)

re : all clean

bonus : all

