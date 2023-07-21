NAME	= libftprintf.a
# TEST	= ft_printf.out

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_printf ft_converter ft_converter2 ft_utils ft_itoa ft_u_itoa ft_hex

CFILES	= $(SRCS:%=%.c)
OFILES	= $(SRCS:%=%.o)

$(NAME):
	$(CC) $(CFLAGS) -c $(CFILES)
	ar rc $(NAME) $(OFILES)
	
# make: $(NAME)
# 	@$(CC) -L. -lftprintf $(CFILES) -o $(TEST)
	
all: $(NAME)

clean:
	@rm -f $(NAME)
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re