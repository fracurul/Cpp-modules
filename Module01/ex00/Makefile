# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 14:51:24 by fracurul          #+#    #+#              #
#    Updated: 2025/07/09 12:54:07 by fracurul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := brainz

CC := c++

CFLAGS := -Wall -Werror -Wextra -std=c++98

OBJDIR := obj

COMMON_SRC = \

SRC = $(COMMON_SRC)

all : $(NAME)

OBJ = $(patsubst src/%.cpp, $(OBJDIR)/%.o, $(SRC))

$(OBJDIR)/%.o : src/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@echo "$(ORANGE)Account compiling...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(VIOLET)Account compiled$(DEF_COLOR)"

clean :
	@echo "$(ORANGE)Deleting all object files...$(DEF_COLOR)"
	@rm -rf $(OBJDIR)
	@echo "$(VIOLET)Object files deleted.$(DEF_COLOR)"

fclean : clean
	@echo "$(ORANGE)Deleting executable files...$(DEF_COLOR)"
	@rm -f $(NAME)
	@echo "$(VIOLET)All executable files has been deleted.$(DEF_COLOR)"

re : fclean all

PHONY: all clean fclean re

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
YELLOW = \033[0;33m
ORANGE = \033[38;5;208m
VIOLET = \033[38;5;93m
GREEN = \033[0;92m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m