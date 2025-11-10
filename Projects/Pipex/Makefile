# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 14:04:06 by hariskon          #+#    #+#              #
#    Updated: 2025/11/10 12:14:43 by hariskon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= pipex
CFLAGS	:= -Wextra -Wall -Werror -g

HEADERS	:= -I ./include
SRCS	:= src/pipex.c src/parsing.c src/helpers.c src/cleanup_utils.c
OBJS 	:= $(SRCS:.c=.o)

LIBFT_DIR  := ./libft

LIBFT  := $(LIBFT_DIR)/libft.a

all: libft $(NAME)

%.o: %.c Makefile
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS) libft Makefile
	$(CC) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR)
	
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libft