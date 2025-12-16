# Makefile
NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MINILIBX_DIR = minilibx-linux
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES = -I./include -I./libft/include -I./$(MINILIBX_DIR)

SRCDIR = src
SRC_BONUS_DIR = bonus
OBJDIR = obj
OBJDIR_BONUS = obj_bonus

SRCS = $(addprefix $(SRCDIR)/, \
	so_long.c window.c init_data.c set_up_map.c load_textures.c checking_map.c path_validation.c \
	exit_error_clear.c player_move.c)

SRCS_BONUS = $(addprefix $(SRC_BONUS_DIR)/, \
so_long_bonus.c cleaner_bonus.c loader_anim.c loader_anim_utils.c) $(addprefix $(SRCDIR)/, \
window.c init_data.c set_up_map.c load_textures.c checking_map.c path_validation.c \
exit_error_clear.c player_move.c)


OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJDIR_BONUS)/%.o)

LIBFT = libft/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

# Colors
GREEN = \033[0;32m
CYAN = \033[0;36m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(NAME)

$(LIBFT):
	@echo "$(CYAN)Compiling libft...$(RESET)"
	@make -C libft

$(MINILIBX):
	@echo "$(CYAN)Compiling MiniLibX...$(RESET)"
	@make -C $(MINILIBX_DIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR_BONUS):
	@mkdir -p $(OBJDIR_BONUS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(CYAN)Compiling...$(RESET)\r"

$(OBJDIR_BONUS)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJDIR_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(CYAN)Compiling bonus...$(RESET)\r"

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ So_long compiled successfully!$(RESET)"

# bonus: $(NAME_BONUS)

bonus: $(LIBFT) $(MINILIBX) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MINILIBX_FLAGS) -o $(NAME_BONUS)
	@echo "$(GREEN)✓ So_long bonus compiled successfully!$(RESET)"

clean:
	@make clean -C libft
	@make clean -C $(MINILIBX_DIR) 2>/dev/null || true
	@rm -rf $(OBJDIR) $(OBJDIR_BONUS)
	@echo "$(GREEN)✓ Object files cleaned$(RESET)"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)✓ All cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus