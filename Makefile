# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 10:14:35 by yusong            #+#    #+#              #
#    Updated: 2021/11/01 13:33:02 by yusong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
FLAGS = -Wextra -Werror -Wall

HEADER = headerfile.h
DYLIB = libmlx.dylib
DYLIB_DIR = minilibx
SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: all

clean:
	rm -rf $(OBJS)
fclean: clean
	$(MAKE) -C $(DYLIB_DIR) clean
	rm -rf $(DYLIB)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(NAME): $(OBJS)
	$(MAKE) -C $(DYLIB_DIR)
	cp $(DYLIB_DIR)/$(DYLIB) .
	$(CC) $(DYLIB) $^ -o $@

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c -o $@ $<