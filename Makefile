NAME	= libftprintf.a
TEST	= ft_printf.out

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_printf ft_putchar ft_strlen

CFILES	= $(SRCS:%=%.c)
OFILES	= $(SRCS:%=%.o)

$(NAME):
	$(CC) $(CFLAGS) -c $(CFILES)
	ar rc $(NAME) $(OFILES)
	
make: $(NAME)
	@gcc -g -L. -lftprintf $(CFILES) -o $(TEST)
	
all: $(NAME)

clean:
	@rm -f $(NAME) $(TEST)
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re