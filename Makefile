# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 12:16:49 by dmylonas          #+#    #+#              #
#    Updated: 2021/10/17 12:52:30 by dmylonas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

COMPILE = gcc -Wall -Werror -Wall -g -pthread
COMPILE_DEV = gcc -g -pthread

SRCS = main.c table_activity.c threads.c init_and_parse.c philo_utils.c libft_utils.c check_death.c

all: $(NAME)

$(NAME): $(SRCS) philo.h
	$(COMPILE) $(SRCS) -o $(NAME)

clean: 
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re