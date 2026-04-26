NAME = push_swap
BONUS = push_swap_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs/
COMMANDS = $(SRC_DIR)commands/push.c \
				$(SRC_DIR)commands/reverse_rotate.c \
				$(SRC_DIR)commands/rotate.c \
				$(SRC_DIR)commands/swap.c
ALGORITHM = $(SRC_DIR)algorithm/algorithm_structure_1.c \
			$(SRC_DIR)algorithm/algorithm_structure_2.c \
			$(SRC_DIR)algorithm/algorithm_structure_3.c \
			$(SRC_DIR)algorithm/algorithm_structure_4.c \
			$(SRC_DIR)algorithm/init_node_a_1.c \
			$(SRC_DIR)algorithm/init_node_a_2.c \
			$(SRC_DIR)algorithm/init_node_b.c
INPUT = $(SRC_DIR)input/ft_split_new.c \
		$(SRC_DIR)input/ft_split_new_2.c \
			$(SRC_DIR)input/handle_errors.c \
			$(SRC_DIR)input/init_stack_a.c \
			$(SRC_DIR)input/main.c
UTILS = $(SRC_DIR)stack_utils/stack_find_len.c
SRCS = $(COMMANDS) $(ALGORITHM) $(INPUT) $(UTILS)

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME):$(LIBFT) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C $(LIBFT_DIR)
fclean: clean
	rm -f $(NAME) $(BONUS)
	make clean -C $(LIBFT_DIR)
re: fclean clean

.PHONY: all clean fclean re
