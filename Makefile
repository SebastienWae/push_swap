# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seb <seb@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:49:18 by swaegene          #+#    #+#              #
#    Updated: 2022/04/06 16:30:36 by seb              ###   ########.fr        #
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
CFLAGS = -g3 
else
OUT_DIR = ./
endif

CC = gcc
CFLAGS += -Wall -Wextra -Werror
CPPFLAGS += -I./include -I./$(FT_PRINTF)/include -I./$(LIBFT)
LDFLAGS += -L./$(FT_PRINTF) -L./$(LIBFT) -lftprintf -lft

SRCS = push_swap.c
OBJS = $(addprefix $(OUT_DIR),$(SRCS:%.c=%.o))

$(NAME): $(DIRS) $(OBJS) $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(OUT_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@

$(FT_PRINTF)/libftprintf.a:
	$(MAKE) -C $(FT_PRINTF) LIBFT_DIR=../$(LIBFT)/

$(LIBFT)/libft.a:
	$(MAKE) -C bonus $(LIBFT)

$(DIRS):
	$(MKDIR) "$@"

bonus: $(NAME)

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re $(MINILIBX) $(FT_PRINTF) $(LIBFT)
