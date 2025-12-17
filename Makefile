# ==================== NAMES ==================== #
NAME        = so_long
BONUS_NAME  = so_long_bonus

# ==================== DIRECTORIES ==================== #
SRCDIR      = src
BONUSDIR    = bonus
INCDIR      = include
OBJDIR      = object
OBJDIR_B    = object_bonus
LIBFT_DIR   = libft
MLX_DIR     = minilibx-linux

# ==================== LIBRARIES ==================== #
LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a

# ==================== SOURCES (MANDATORY) ==================== #
SRCS        = $(addprefix $(SRCDIR)/, \
				checking_map.c \
				exit_error_clear.c \
				init_data.c \
				load_textures.c \
				path_validation.c \
				player_move.c \
				set_up_map.c \
				so_long.c \
				window.c)

# ==================== SOURCES (BONUS) ==================== #
# Fichiers partagés entre mandatory et bonus
SHARED_SRCS = $(addprefix $(SRCDIR)/, \
				checking_map.c \
				exit_error_clear.c \
				init_data.c \
				load_textures.c \
				path_validation.c \
				player_move.c \
				set_up_map.c)

# Fichiers spécifiques au bonus
BONUS_SRCS  = $(addprefix $(BONUSDIR)/, \
				so_long_bonus.c \
				window_bonus.c \
				player_move_bonus.c \
				loader_anim.c \
				loader_anim_utils.c)

# Tous les fichiers pour la compilation bonus
ALL_BONUS   = $(SHARED_SRCS) $(BONUS_SRCS)

# ==================== OBJECTS ==================== #
OBJS        = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJS_BONUS  = $(SHARED_SRCS:$(SRCDIR)/%.c=$(OBJDIR_B)/%.o) \
              $(BONUS_SRCS:$(BONUSDIR)/%.c=$(OBJDIR_B)/%.o)

# ==================== COMPILER & FLAGS ==================== #
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g
INCLUDES    = -I$(INCDIR) -I$(LIBFT_DIR)/include -I$(MLX_DIR)
LDFLAGS     = -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -lmlx -lXext -lX11 -lm

# ==================== COLORS ==================== #
GREEN       = \033[0;32m
CYAN        = \033[0;36m
YELLOW      = \033[0;33m
RED         = \033[0;31m
RESET       = \033[0m

# ==================== RULES ==================== #

all: $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)✓ Linking $(NAME)...$(RESET)"

bonus: $(BONUS_NAME)
	@echo "$(GREEN)✓ $(BONUS_NAME) compiled successfully!$(RESET)"

$(BONUS_NAME): $(LIBFT) $(MLX) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LDFLAGS) -o $(BONUS_NAME)
	@echo "$(GREEN)✓ Linking $(BONUS_NAME)...$(RESET)"

# ==================== OBJECTS COMPILATION ==================== #

# Mandatory objects
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@printf "$(CYAN)Compiling mandatory: %-30s$(RESET)\r" $<
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Bonus objects - fichiers du dossier src
$(OBJDIR_B)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR_B)
	@printf "$(CYAN)Compiling bonus (shared): %-30s$(RESET)\r" $<
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Bonus objects - fichiers du dossier bonus
$(OBJDIR_B)/%.o: $(BONUSDIR)/%.c
	@mkdir -p $(OBJDIR_B)
	@printf "$(CYAN)Compiling bonus: %-30s$(RESET)\r" $<
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ==================== LIBRARIES ==================== #

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@echo "$(YELLOW)Building minilibx...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

# ==================== CLEANING ==================== #

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory 2>/dev/null || true
	@rm -rf $(OBJDIR) $(OBJDIR_B)
	@echo "$(CYAN)✓ Object files removed$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "$(CYAN)✓ $(NAME) and $(BONUS_NAME) removed$(RESET)"

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus run run_bonus valgrind