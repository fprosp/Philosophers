# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 14:50:58 by gimartin          #+#    #+#              #
#    Updated: 2022/05/17 14:54:46 by gimartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRC = checks.c \
		error.c \
		get.c \
		philo_bonus.c \
		print_error.c \
		single_process.c \
		table.c \
		time.c \
		utils.c		

SRCS = $(addprefix src/, $(SRC))

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -pthread -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
