# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 15:58:40 by emilgarc          #+#    #+#              #
#    Updated: 2025/07/21 17:13:41 by emilgarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = 	main.c\
		utils.c\
		start.c\
		crochet.c\
		routine.c\
		instructor.c

RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
RESET       = \033[0m

HEADER = ./src/philo.h

MANPATH = $(addprefix ./src/, $(SRC))

FLAGS = -Wall -Wextra -Werror 

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(MANPATH) $(HEADER)
	@echo "$(YELLOW)Compiling the program$(RESET)"
	@echo "$(YELLOW)...$(RESET)"
	@cc $(FLAGS) -o $(NAME) $(MANPATH)
	@echo "$(YELLOW)DONE!!$(RESET)"

clean:
	@echo "$(RED)Cleaning ...$(RESET)"
	@rm -f $(NAME)

fclean: clean
	@echo "$(RED)Cleaning everything...$(RESET)"
	@rm -f $(NAME)

re: fclean all