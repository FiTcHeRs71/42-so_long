# ================================ VARIABLES ================================= #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MINILIBX_DIR = minilibx-linux
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES = -I./include -I./libft/include -I./$(MINILIBX_DIR)

# Directories
SRCDIR = src
SRC_BONUS_DIR = bonus
OBJDIR = obj
OBJDIR_BONUS = obj_bonus

# Libraries
LIBFT = libft/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

# Colors
GREEN = \033[0;32m
CYAN = \033[0;36m
YELLOW = \033[0;33m
RESET = \033[0m

# ============================== MANDATORY SRCS ============================== #

SRCS = $(addprefix $(SRCDIR)/, \
	so_long.c \
	window.c \
	init_data.c \
	set_up_map.c \
	load_textures.c \
	checking_map.c \
	path_validation.c \
	exit_error_clear.c \
	player_move.c)

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# ================================ BONUS SRCS ================================ #

# Fichiers bonus uniquement (4 fichiers)
SRCS_BONUS_ONLY = $(addprefix $(SRC_BONUS_DIR)/, \
	so_long_bonus.c \
	window_bonus.c \
	loader_anim.c \
	loader_anim_utils.c)

# Fichiers mandatory réutilisés (8 fichiers)
SRCS_SHARED = $(addprefix $(SRCDIR)/, \
	window.c \
	init_data.c \
	set_up_map.c \
	load_textures.c \
	checking_map.c \
	path_validation.c \
	exit_error_clear.c \
	player_move.c)

# Objets bonus
OBJS_BONUS_ONLY = $(SRCS_BONUS_ONLY:$(SRC_BONUS_DIR)/%.c=$(OBJDIR_BONUS)/%.o)
OBJS_SHARED = $(SRCS_SHARED:$(SRCDIR)/%.c=$(OBJDIR_BONUS)/%.o)
OBJS_BONUS = $(OBJS_BONUS_ONLY) $(OBJS_SHARED)

# ================================== RULES =================================== #

all: $(NAME)

# ----------------------------- MANDATORY BUILD ------------------------------ #

$(LIBFT):
	@echo "$(CYAN)Compiling libft...$(RESET)"
	@make -C libft --no-print-directory

$(MINILIBX):
	@echo "$(CYAN)Compiling MiniLibX...$(RESET)"
	@make -C $(MINILIBX_DIR) --no-print-directory

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR_BONUS):
	@mkdir -p $(OBJDIR_BONUS)

# Compilation objets mandatory
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(CYAN)Compiling mandatory...$(RESET)\r"

# Linking mandatory
$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ So_long compiled successfully!$(RESET)                    "

# ------------------------------- BONUS BUILD -------------------------------- #

# Compilation objets bonus uniquement
$(OBJDIR_BONUS)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJDIR_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(CYAN)Compiling bonus files...$(RESET)\r"

# Compilation objets shared (mandatory réutilisés pour bonus)
$(OBJDIR_BONUS)/%.o: $(SRCDIR)/%.c | $(OBJDIR_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(CYAN)Compiling shared files...$(RESET)\r"

# Linking bonus
bonus: $(LIBFT) $(MINILIBX) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MINILIBX_FLAGS) -o $(NAME_BONUS)
	@echo "$(GREEN)✓ So_long bonus compiled successfully!$(RESET)              "

# ================================= CLEANING ================================= #

clean:
	@make clean -C libft --no-print-directory
	@make clean -C $(MINILIBX_DIR) 2>/dev/null || true
	@rm -rf $(OBJDIR) $(OBJDIR_BONUS)
	@echo "$(GREEN)✓ Object files cleaned$(RESET)"

fclean: clean
	@make fclean -C libft --no-print-directory
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)✓ All cleaned$(RESET)"

re: fclean all

# ================================== PHONY =================================== #

.PHONY: all clean fclean re bonus