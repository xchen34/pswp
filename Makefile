# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leochen <leochen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 15:40:06 by leochen           #+#    #+#              #
#    Updated: 2024/01/27 23:06:40 by leochen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

SRCS = 	init_stack.c operation_pu.c operation_r.c operation_rr.c \
operation_sw.c sort_algo.c sort.c utils.c utils2.c main.c ft_split.c ft_putstr_fd.c utils3.c

SRCS_BONUS = get_next_line.c get_next_line_utils.c checker.c check_utils.c ft_strncmp.c \
init_stack.c operation_pu.c operation_r.c operation_rr.c utils3.c\
operation_sw.c sort_algo.c sort.c utils.c utils2.c ft_split.c ft_putstr_fd.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
	
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus : $(NAME) $(BONUS)

$(BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

.PHONY: all clean fclean re 
