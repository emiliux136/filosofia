# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 15:58:40 by emilgarc          #+#    #+#              #
#    Updated: 2025/07/08 12:52:05 by emilgarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = 	main.c\
		utils.c\
		start.c\
		crochet.c\
		routine.c

HEADER = ./src/philo.h

MANPATH = $(addprefix ./src/, $(SRC))

FLAGS = -Wall -Wextra -Werror 

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(MANPATH) $(HEADER)
	@cc $(FLAGS) -o $(NAME) $(MANPATH)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all