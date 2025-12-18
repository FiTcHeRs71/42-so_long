# ==================== NOMS ==================== #
NAME        = so_long
BONUS_NAME  = so_long_bonus

# ==================== RÉPERTOIRES ==================== #
SRCDIR      = src
BONUSDIR    = bonus/src_bonus
INCDIR      = include
BONUS_INCDIR= include_bonus
OBJDIR      = object
OBJDIR_B    = object_bonus
LIBFT_DIR   = libft
MLX_DIR     = minilibx-linux

# ==================== BIBLIOTHÈQUES ==================== #
LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a

# ==================== SOURCES ==================== #
# Sources Partie Obligatoire
SRCS        = $(addprefix $(SRCDIR)/, \
				so_long.c \
				checking_map.c \
				exit_error_clear.c \
				init_data.c \
				load_textures.c \
				path_validation.c \
				player_move.c \
				set_up_map.c \
				window.c)

# Sources Partie Bonus (Tout est indépendant)
BONUS_SRCS  = $(addprefix $(BONUSDIR)/, \
				so_long_bonus.c \
				checking_map_bonus.c \
				init_data_bonus.c \
				load_textures_bonus.c \
				set_up_map_bonus.c \
				monster_bonus.c \
				exit_error_clear_bonus.c \
				path_validation_bonus.c \
				player_move_bonus.c \
				window_bonus.c \
				menu_bonus.c \
				loader_anim_bonus.c \
				loader_anim_utils_bonus.c)

# ==================== OBJETS ==================== #
OBJS        = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJS_BONUS  = $(BONUS_SRCS:$(BONUSDIR)/%.c=$(OBJDIR_B)/%.o)

# ==================== COMPILATEUR & FLAGS ==================== #
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g3
# Includes spécifiques pour éviter les conflits de headers
INCLUDES    = -I$(INCDIR) -I$(LIBFT_DIR)/include -I$(MLX_DIR)
INCLUDES_B  = -I$(BONUS_INCDIR) -I$(LIBFT_DIR)/include -I$(MLX_DIR)

LDFLAGS     = -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -lmlx -lXext -lX11 -lm

# ==================== COULEURS (Juste pour le style) ==================== #
GREEN       = \033[0;32m
CYAN        = \033[0;36m
YELLOW      = \033[0;33m
RESET       = \033[0m

# ==================== RÈGLES ==================== #

all: $(NAME)

# Compilation du Mandatory
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

# Compilation du Bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(MLX) $(OBJS_BONUS)
	@echo "$(YELLOW)Linking $(BONUS_NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LDFLAGS) -o $(BONUS_NAME)
	@echo "$(GREEN)✓ $(BONUS_NAME) compiled successfully!$(RESET)"

# ==================== COMPILATION DES OBJETS ==================== #

# Création du dossier object et compilation mandatory
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Création du dossier object_bonus et compilation bonus
$(OBJDIR_B)/%.o: $(BONUSDIR)/%.c
	@mkdir -p $(OBJDIR_B)
	@$(CC) $(CFLAGS) $(INCLUDES_B) -c $< -o $@

# ==================== LIBS EXTERNES ==================== #

$(LIBFT):
	@echo "$(YELLOW)Building Libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@echo "$(YELLOW)Building MiniLibX...$(RESET)"
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

# ==================== NETTOYAGE ==================== #

clean:
	@rm -rf $(OBJDIR) $(OBJDIR_B)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@# $(MAKE) -C $(MLX_DIR) clean --no-print-directory  <-- Decommenter si besoin
	@echo "$(CYAN)✓ Objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(CYAN)✓ Executables removed$(RESET)"

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus
