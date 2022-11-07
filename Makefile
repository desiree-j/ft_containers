# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 07:05:44 by djedasch          #+#    #+#              #
#    Updated: 2022/10/31 07:17:40 by djedasch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ./ft_containers

SRCS	=  vector.cpp map.cpp stack.cpp main.cpp

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