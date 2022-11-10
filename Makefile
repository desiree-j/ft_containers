# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 07:05:44 by djedasch          #+#    #+#              #
#    Updated: 2022/11/10 12:30:00 by djedasch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ./ft_containers

SRCS	=  main_vector.cpp

OBJS	= $(SRCS:.cpp=.o)

CC		= c++

CFLACS 	= -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLACS) -c $^

$(NAME): $(OBJS)
	$(CC) $(CFLACS) $^ -o $(NAME)

clean: 
	rm -f $(OBJS) 

fclean: 
	rm -f $(NAME) $(OBJS) 

re: fclean all

.PHONY: all fclean re 