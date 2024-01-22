# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leochen <leochen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 15:40:06 by leochen           #+#    #+#              #
#    Updated: 2024/01/22 13:58:01 by leochen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = 	init_stack.c operation_pu.c operation_r.c operation_rr.c \
operation_sw.c sort_algo.c sort.c utils.c utils2.c main.c ft_split.c ft_putstr_fd.c
CC = cc
CFLAGS = -Wall -Wextra -Werror 
	
all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)	

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 