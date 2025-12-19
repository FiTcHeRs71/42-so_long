/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:08:58 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/19 12:08:58 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "so_long_struct_bonus.h"
# include <X11/keysym.h>

/* checking_map_bonus.c */
void	check_map(t_mlx *mlx, char **args);
void	check_arg(char *line, t_mlx *mlx);
void	check_flag(t_mlx *mlx);
void	ft_count_and_check_args(char c, t_mlx *mlx);
void	check_line_empty(t_mlx	*mlx, char *line, int fd);

/* init_data_bonus.c */
void	init_data(t_mlx *mlx, char **argv);
char	**fill_args(t_mlx *mlx, int fd);
int		count_line(char **args);
void	check_map_border(t_mlx *mlx);
void	check_map_border_2(t_mlx *mlx);

/* load_textures_bonus.c */
void	load_textures(t_mlx *mlx);
void	load_enemy(t_mlx *mlx);
void	load_hp_textures(t_mlx *mlx);
void	init_player(t_mlx *mlx);

/* set_up_map_bonus.c */
void	set_up_map(t_mlx *mlx);
void	draw_with_img(t_mlx *mlx, char c, int x, int y);
void	render_line(char *line, t_mlx *mlx, int y);

/* player_move_bonus.c */
int		handle_keyboard_bonus(int keycode, t_mlx *mlx);
int		game_loop(t_mlx *mlx);
void	player_move(t_mlx *mlx, int move);

/* window_bonus.c */
void	handle_window_bonus(t_mlx *mlx);
int		handle_keyrelease(int keycode, t_mlx *mlx);
void	render_hud(t_mlx *mlx);
void	render_hp(t_mlx *mlx);

/* exit_error_clear_bonus.c */
void	ft_error(char *str, t_mlx *mlx);
int		close_window(t_mlx *mlx);
void	free_player_animations(t_mlx *mlx);
void	free_image(t_mlx *mlx);

/* loader_anim_bonus.c & utils */
void	load_player_animations(t_mlx *mlx);
char	*build_sprite_path(t_mlx *mlx, char *dir, int frame);
void	*load_sprite(t_mlx *mlx, char *path);
void	update_player_animation(t_mlx *mlx);
void	render_player(t_mlx *mlx);
void	load_dir_frames(t_mlx *mlx, int move, char *dir);
void	init_animation(t_animation *anim);
void	next_frame_cycle(t_animation *anim, int *next_frame);

/* path_validation_bonus.c */
void	valide_path(t_mlx *mlx);
void	flood_fill(char **map_copy, int x, int y, t_flood *flood);
char	**copy_map(char **original, t_mlx *mlx);
int		find_player_position(char **map, int *x, int *y);

/* menu_bonus.c */
void	render_menu(t_mlx *mlx);
int		handle_menu_keys(int keycode, t_mlx *mlx);

/* monster_bonus & utils  */
void	render_enemy(t_mlx *mlx);
void	*get_enemy_sprite(t_mlx *mlx, int dir);
void	init_enemy(t_mlx *mlx);
void	move_enemy(t_mlx *mlx, t_enemy *enemy);
void	update_enemy(t_mlx *mlx);
int		maj_enemy_struct(t_mlx *mlx, int index, int x, int y);
void	try_move_enemy_vertical(t_mlx *mlx, t_enemy *enemy, int *new_y);
void	try_move_enemy(t_mlx *mlx, t_enemy *enemy, int *new_x);

/* player_attack.c */
void	kill_enemy(t_mlx *mlx, int enemy_index);
void	check_attack_hit(t_mlx *mlx, int target_x, int target_y);
void	player_attack(t_mlx *mlx);
void	trigger_game_over(t_mlx *mlx);

#endif