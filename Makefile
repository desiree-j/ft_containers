# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 07:05:44 by djedasch          #+#    #+#              #
#    Updated: 2022/10/31 07:13:15 by djedasch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ./ft_containers

SRCS	=  vector.cpp map.cpp stack.cpp main.cpp

CC		= c++

CFLACS 	= -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLACS) $^ -o $(NAME)

$(OBJS): %.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) 

fclean: 
	rm -f $(NAME) $(OBJS) 

re: fclean all

.PHONY: all fclean re 