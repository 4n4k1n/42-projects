NAME =			push_swap
NAME_BONUS =	checker

CC =			cc
CFLAGS =		-Wall -Wextra -Werror -g
LIBFT =			libft/libft.a

SRC_DIR =		src
OBJ_DIR =		obj

VPATH =			$(SRC_DIR):\
				$(SRC_DIR)/parsing:\
				$(SRC_DIR)/logic:\
				$(SRC_DIR)/utils:\
				$(SRC_DIR)/operations:\
				$(SRC_DIR)/llist:\
				$(SRC_DIR)/checker

INCLUDES =		-Iinc

MAIN_SRCS =		main.c

PARSING_SRCS =	alloc_args.c \
				count_numbers.c \
				parsing.c \
				valid_input.c \
				is_unique.c \
				index_llist.c

LOGIC_SRCS =	logic.c \
				edge_cases.c

UTILS_SRCS =	cwords.c \
				ft_exit.c \
				get_stacks.c \
				ft_sqrt.c \
				is_sorted.c \
				edge_cases_utils.c

OPER_SRCS = 	pa_pb.c \
				ra_rb_rr.c \
				rra_rrb_rrr.c \
				sa_sb_ss.c

LLIST_SRCS =	create_llist.c

CHECKER_SRCS =	checker.c

SRCS :=			$(MAIN_SRCS) $(PARSING_SRCS) $(LOGIC_SRCS) $(UTILS_SRCS) $(OPER_SRCS) $(LLIST_SRCS)

BONUS_SRCS :=	$(PARSING_SRCS) $(OPER_SRCS) $(LLIST_SRCS) $(UTILS_SRCS) $(CHECKER_SRCS)

OBJS :=			$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

BONUS_OBJS :=	$(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_DIR) $(BONUS_OBJS) $(LIBFT)
	$(CC) $(BONUS_OBJS) $(LIBFT) -o $(NAME_BONUS)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

bre: fclean bonus

mb: all bonus

mbre: bre mb

.PHONY: all bonus clean fclean re bre