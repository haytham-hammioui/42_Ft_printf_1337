NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
		ft_putaddrs.c \
		ft_putchar.c \
		ft_putnbr_base.c \
		ft_putnbr_unsigned.c \
		ft_putnbr.c \
		ft_putstr.c \
		
OBJ = $(SRC:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean