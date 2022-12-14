# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 07:05:44 by djedasch          #+#    #+#              #
#    Updated: 2022/11/26 20:43:28 by djedasch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ./ft_containers

SRCS		= main.cpp

VEC_SRCS 	= main_vector.cpp

UTIL_SRCS 	= main_reverse_iterator.cpp

STACK_SRCS	= main_stack.cpp

MAP_SRCS	= main_map.cpp

OBJS		= $(SRCS:.cpp=.o)

CC			= c++

CFLACS 		= -Wall -Werror -Wextra -std=c++98 -g3

all: $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLACS) -c $^
$(VEC_OBJS): $(VEC_SRCS)
	$(CC) $(CFLACS) -c $^
$(UTI_OBJS): $(UTIL_SRCS)
	$(CC) $(CFLACS) -c $^

$(NAME): $(OBJS)
	$(CC) $(CFLACS) $^ -o $(NAME)

vector: $(VEC_SRCS)
	$(CC) $(CFLACS) $^ -o ft_vector

iterator: $(UTIL_SRCS)
	$(CC) $(CFLACS) $^ -o ft_iterator

stack: $(STACK_SRCS)
	$(CC) $(CFLACS) $^ -o ft_stack

map: $(MAP_SRCS)
	$(CC) $(CFLACS) $^ -o ft_map

clean: 
	rm -f $(OBJS) 

fclean: 
	rm -f $(NAME) $(OBJS) 
re: fclean all

.PHONY: all fclean re 