NAME := libftprintf.a

SRC := ft_printf.c ft_printfchr.c ft_printfstr.c ft_printfint.c ft_putnumprintf.c
OBJS := $(patsubst %.c, %.o, $(SRC))

CC := cc 

CFLAGS := -Wall -Wextra -Werror

LIBFLAGS:= -I . -I ../libft

LIBFT_DIR:= ../libft/libft.a

RM := rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcsuU $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: clean all

test: 
	cc main.c -L. -lftprintf -L ../libft/ -lft