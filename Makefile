PUSHSWAP = push_swap

# CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g -I$(SRC_PATH)push_swap.h $(FT_PRINTF_A) $(LIBFT_A)
CFLAGS = -Wall -Werror -Wextra -I$(SRC_PATH)push_swap.h $(FT_PRINTF_A) $(LIBFT_A)
FLAGS = -Wall -Werror -Wextra 
SRC_PATH = ./srcs/

FT_PRINTF_A = $(SRC_PATH)ft_printf/libftprintf.a
LIBFT_A = $(SRC_PATH)ft_printf/libft/libft.a

FILES = $(SRC_PATH)main.c \
		$(SRC_PATH)error.c \
		$(SRC_PATH)utils.c \
		$(SRC_PATH)parse_args.c \
		$(SRC_PATH)node_manage.c \
		$(SRC_PATH)ft_radixsort.c \
		$(SRC_PATH)sort_actions.c \
		$(SRC_PATH)sort_shorts.c \
		$(SRC_PATH)sort_support.c \

all: $(PUSHSWAP)

$(FT_PRINTF_A): $(LIBFT)
	make -C $(SRC_PATH)ft_printf

$(LIBFT_A): 
	make -C $(SRC_PATH)ft_printf/libft

$(PUSHSWAP):
	@make -C $(SRC_PATH)ft_printf/libft
	@make -C $(SRC_PATH)ft_printf
	@gcc $(CFLAGS) $(FILES) -o $(PUSHSWAP)
	@echo "Success!"

clean:
	make -C $(SRC_PATH)ft_printf clean

fclean: clean
	rm -f $(PUSHSWAP)
	make -C $(SRC_PATH)ft_printf fclean

re: fclean all