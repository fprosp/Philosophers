# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 15:24:08 by fprosper          #+#    #+#              #
#    Updated: 2023/04/07 17:33:02 by fprosper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG_NAME = philo
PROG_MAIN = main.c
FUNCS 		=  	check_n_get.c free_gest.c time_gest.c philo_routine.c deaths.c \
				atoi.c
FUNC_OBJS = $(FUNCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -lpthread
RM = rm -f

$(PROG_NAME):		$(FUNC_OBJS)
					$(CC) $(CFLAGS) -o $(PROG_NAME) $(FUNC_OBJS) $(PROG_MAIN)

all:				$(PROG_NAME)

clean:				
					$(RM) $(FUNC_OBJS)

fclean:				clean
					$(RM) $(FUNC_OBJS) $(PROG_NAME)

re:					fclean all

.PHONY:				all clean fcelan re