CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_put_hex.c ft_putchar.c ft_putstr.c ft_put_pointer.c ft_putnbr.c ft_put_unsigned.c ft_printf.c
SRC_BONUS = bonus/ft_put_hex_bonus.c bonus/ft_putchar_bonus.c bonus/ft_putstr_bonus.c bonus/ft_put_pointer_bonus.c\
			bonus/ft_putnbr_bonus.c bonus/ft_put_unsigned_bonus.c bonus/ft_printf_bonus.c
OBJ_SRC = $(SRC:.c=.o)
BNS_SRC = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SRC)
	ar rc $(NAME) $(OBJ_SRC)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
bonus: $(BNS_SRC)
	ar rc $(NAME) $(BNS_SRC)

bonus/%.o: bonus/%.c bonus/ft_printf_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_SRC) $(BNS_SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus 