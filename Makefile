# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 15:24:08 by fprosper          #+#    #+#              #
#    Updated: 2023/03/20 15:49:26 by fprosper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG_NAME = philo
PROG_MAIN = main.c
FUNC = check_get_init.c ascii_to_int.c
FUNC_OBJS = $(FUNC:.c=.o)

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