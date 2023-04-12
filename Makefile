# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 15:24:08 by fprosper          #+#    #+#              #
#    Updated: 2023/04/12 14:11:05 by fprosper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG_NAME = philo
PROG_MAIN = main.c
FUNCS = atoi.c check_n_get.c deaths.c free_print.c time_gest.c
FUNC_OBJS = $(FUNCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
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