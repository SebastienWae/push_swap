# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seb <seb@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:49:18 by swaegene          #+#    #+#              #
#    Updated: 2022/04/16 21:28:49 by seb              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

RM = rm -f
MKDIR = mkdir

FT_PRINTF = ft_printf
LIBFT = libft

SRC_DIR = ./src/

ifdef MAKE_DEBUG
OUT_DIR = ./debug/
NAME := $(OUT_DIR)$(NAME)
DIRS = $(OUT_DIR)
#CFLAGS = -g3 -fsanitize=address
CFLAGS = -g3
else
OUT_DIR = ./
endif

CC = gcc
CFLAGS += -Wall -Wextra -Werror
CPPFLAGS += -I./include -I./$(FT_PRINTF)/include -I./$(LIBFT)
LDFLAGS += -L./$(FT_PRINTF) -L./$(LIBFT) -lftprintf -lft

SRCS = push_swap.c stacks.c arguments.c exit.c operations.c sort.c \
	op_swap.c op_push.c op_reverse_rotate.c op_rotate.c list.c op_multi.c \
	bfs.c math.c direction.c mergesort.c chunk.c
OBJS = $(addprefix $(OUT_DIR),$(SRCS:%.c=%.o))

$(NAME): $(DIRS) $(OBJS) $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(OUT_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@

$(FT_PRINTF)/libftprintf.a:
	$(MAKE) -C $(FT_PRINTF) LIBFT_DIR=../$(LIBFT)/

$(LIBFT)/libft.a:
	$(MAKE) -C $(LIBFT) bonus

$(DIRS):
	$(MKDIR) "$@"

check: CFLAGS = -fanalyzer
check: re

bonus: $(NAME)

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

compile_commands:
	compiledb -f make re

.PHONY: all clean fclean re $(MINILIBX) $(FT_PRINTF) $(LIBFT)
