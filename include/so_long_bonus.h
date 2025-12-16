
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/* cleaner_bonus */
void	free_player_animations(t_mlx *mlx);

/* loader_anim.c */
void	*load_sprite(t_mlx *mlx, char *path);
char	*build_sprite_path(t_mlx *mlx, char *dir, int frame);
void	init_animation(t_animation *anim);
void	load_dir_frames(t_mlx *mlx, int move, char *dir);
void	load_player_animations(t_mlx *mlx);

/* loader_anim_utils.c */
void	render_player(t_mlx *mlx);
void	update_player_animation(t_mlx *mlx);
void	next_frame_cycle(t_animation *anim, int *next_frame);

/* player_move_bonus.c */
int	handle_keyboard_bonus(int keycode, t_mlx *mlx);
int	game_loop(t_mlx *mlx);

#endif