# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 14:04:06 by hariskon          #+#    #+#              #
#    Updated: 2025/11/06 17:04:41 by hariskon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= pipex
CFLAGS	:= -Wextra -Wall -Werror -g

HEADERS	:= -I ./include
SRCS	:= src/pipex.c src/parsing.c src/helpers.c src/free.c
OBJS 	:= $(SRCS:.c=.o)

LIBFT_DIR  := ./libft

LIBFT  := $(LIBFT_DIR)/libft.a

all:$(LIBFT) $(PRINTF) $(NAME)

%.o:make %.c Makefile
	@cc $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) Makefile
	@cc $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)
	
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
