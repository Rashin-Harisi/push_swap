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
LIBFT		= libft.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.a .

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME) libft.a libftprintf.a
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all bonus clean fclean re
