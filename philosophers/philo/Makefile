NAME = philo

SRC = checks.c \
		errors.c \
		hand.c \
		philo.c \
		table.c \
		time.c \
		utils.c \
		utils2.c \
		write.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC) -pthread -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
