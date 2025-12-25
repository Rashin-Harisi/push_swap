NAME		= push_swap

SRC		= push_swap.c \
		actions_push.c \
		small_sorting.c \
		turk_sorting.c\
		actions_reverse_rotate.c\
		actions_rotate.c\
		actions_swap.c\
		helper_general.c\
		helper_general_second.c\
		helper_small_sorting.c\
		helper_turk_actions_sorting.c\
		helper_turk_sorting.c\

OBJ		= $(SRC:.c=.o)

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

FT_PRINTF_PATH	= ./ft_printf
FT_PRINTF	= $(FT_PRINTF_PATH)/libftprintf.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_PATH)
	$(MAKE) clean -C $(FT_PRINTF_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(MAKE) fclean -C $(FT_PRINTF_PATH)

re: fclean all

.PHONY: all bonus clean fclean re
