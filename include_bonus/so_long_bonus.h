
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "so_long_struct_bonus.h"
# include <X11/keysym.h>

/* --- PROTOTYPES --- */

/* checking_map_bonus.c */
void	check_map(t_mlx *mlx, char **args);
void	check_arg(char *line, t_mlx *mlx);
void	check_flag(t_mlx *mlx);

/* init_data_bonus.c */
void	init_data(t_mlx *mlx, char **argv);
char	**fill_args(int fd);
int		count_line(char **args);
void	check_map_border(t_mlx *mlx);
void	check_map_border_2(t_mlx *mlx);

/* load_textures_bonus.c */
void	load_textures(t_mlx *mlx);

/* set_up_map_bonus.c */
// Note : Déplace ce fichier de texture_bonus vers src_bonus, c'est mieux !
void	set_up_map(t_mlx *mlx);
void	draw_with_img(t_mlx *mlx, char c, int x, int y);

/* player_move_bonus.c */
int		handle_keyboard_bonus(int keycode, t_mlx *mlx);
void	player_move(t_mlx *mlx, int move); // Si tu as gardé la logique de move
int		game_loop(t_mlx *mlx);

/* window_bonus.c */
void	handle_window_bonus(t_mlx *mlx);
int		close_window(t_mlx *mlx);
int		handle_keyrelease(int keycode, t_mlx *mlx);

/* exit_error_clear_bonus.c */
void	ft_error(char *str, t_mlx *mlx);
void	free_all(t_mlx *mlx);
// Ajoute ici les fonctions de free spécifiques au bonus (anim, etc.)

/* loader_anim_bonus.c & utils */
void	load_player_animations(t_mlx *mlx);
void	update_player_animation(t_mlx *mlx);
void	render_player(t_mlx *mlx);

/* path_validation_bonus.c (si tu l'as) */
void	validate_path(t_mlx *mlx);


#endif