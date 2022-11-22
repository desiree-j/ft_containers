# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djedasch <djedasch@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 07:05:44 by djedasch          #+#    #+#              #
#    Updated: 2022/11/22 15:30:09 by djedasch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ./ft_containers

SRCS		= main.cpp

VEC_SRCS 	= main_vector.cpp

UTIL_SRCS 	= main_reverse_iterator.cpp

OBJS		= $(SRCS:.cpp=.o)

#VEC_OBJS	= $(VEC_SRCS:.cpp=.o)

#UTIL_OBJS	= $(UTIL_SRCS:.cpp=.o)

CC			= c++

CFLACS 		= -Wall -Werror -Wextra -std=c++98

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

clean: 
	rm -f $(OBJS) 

fclean: 
	rm -f $(NAME) $(OBJS) 
re: fclean all

.PHONY: all fclean re 