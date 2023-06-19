# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedelin <tedelin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 17:24:24 by tedelin           #+#    #+#              #
#    Updated: 2023/06/19 10:35:49 by tedelin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00
SRC = $(addprefix src/, Bureaucrat.cpp main.cpp)
HEADER = $(addprefix include/, Bureaucrat.hpp)
INCLUDE = -I./include
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJ)

obj/%.o: src/%.cpp $(HEADER)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
clean:
	rm -f $(OBJ)
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re