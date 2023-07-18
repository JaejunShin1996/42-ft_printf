NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_printf 

CFILES	= $(SRCS:%=%.c)
OFILES	= $(SRCS:%=%.o)

$(NAME):
	$(CC) $(CFLAGS) -c $(CFILES)
	ar rc $(NAME) $(OFILES)
	
all: $(NAME)

clean:
	rm -f $(NAME)
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re