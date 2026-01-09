NAME		= push_swap
BONUS_NAME	= checker

COMMON_SRC	= utilities/actions_push.c \
		utilities/actions_reverse_rotate.c\
		utilities/actions_rotate.c\
		utilities/actions_swap.c\
		utilities/helper_general.c\
		utilities/helper_general_second.c\
		utilities/helper_general_third.c

MANDATORY_SRC	= push_swap.c\
		small_sorting.c\
		turk_sorting.c\
		utilities/helper_small_sorting.c\
		utilities/helper_turk_actions_sorting.c\
		utilities/helper_turk_sorting.c

BONUS_SRC	= bonus/checker.c\
		bonus/helper_checker.c\
		bonus/get_next_line/get_next_line.c\
		bonus/get_next_line/get_next_line_utils.c

MANDATORY_OBJ	= $(MANDATORY_SRC:.c=.o)
COMMON_OBJ	= $(COMMON_SRC:.c=.o)
BONUS_OBJ	= $(BONUS_SRC:.c=.o)

LIBFT_PATH	= ./libft
LIBFT		= libft.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(MANDATORY_OBJ) $(COMMON_OBJ)
	$(CC) $(CFLAGS) $(MANDATORY_OBJ) $(COMMON_OBJ) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJ) $(COMMON_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(COMMON_OBJ) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.a .

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJ) $(COMMON_OBJ) $(BONUS_OBJ)
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) libft.a libftprintf.a
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all bonus clean fclean re
