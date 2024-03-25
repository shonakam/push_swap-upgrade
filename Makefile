PUSHSWAP = push_swap

# CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g -I$(PATH)push_swap.h $(FT_PRINTF_A) $(LIBFT_A)
CFLAGS = -Wall -Werror -Wextra -I$(PATH)push_swap.h $(FT_PRINTF_A) $(LIBFT_A)
FLAGS = -Wall -Werror -Wextra 
PATH = ./srcs/

FT_PRINTF_A = $(PATH)ft_printf/libftprintf.a
LIBFT_A = $(PATH)ft_printf/libft/libft.a

FILES = $(PATH)main.c \
		$(PATH)error.c \
		$(PATH)utils.c \
		$(PATH)parse_args.c \
		$(PATH)node_manage.c \
		$(PATH)ft_radixsort.c \
		$(PATH)sort_actions.c \
		$(PATH)sort_shorts.c \
		$(PATH)sort_support.c \

all: $(PUSH_SWAP)

$(FT_PRINTF_A): $(LIBFT)
	make -C $(PATH)ft_printf

$(LIBFT_A): 
	make -C $(PATH)ft_printf/libft

$(PUSH_SWAP):
	@make -C $(PATH)ft_printf/libft
	@make -C $(PATH)ft_printf
	@gcc $(CFLAGS) $(FILES) -o $(PUSHSWAP)
	@echo "Success!"

clean:
	make fclean -C $(PATH)ft_printf

fclean: clean
	rm -f $(PUSHSWAP)

re: fclean all