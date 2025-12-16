/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:35:08 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/16 18:35:18 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "so_long_struct.h"
# include "so_long_bonus.h"
# include <X11/keysym.h>

/* window.c */
void	handle_window(t_mlx *mlx);
int		handle_keyboard_input(int keycode, t_mlx *mlx);

/* init_data.c */
void	init_data(t_mlx *mlx, char **argv);
int		count_line(char **args);
char	**fill_args(int fd);
void	check_map_border_2(t_mlx *mlx);
void	check_map_border(t_mlx *mlx);

/* set_up_map.c */
void	set_up_map(t_mlx *mlx);
void	render_line(char *line, t_mlx *mlx, int y);
void	draw_with_img(t_mlx *mlx, char c, int x, int y);

/* load_textures.c */
void	load_textures(t_mlx *mlx);
void	init_player(t_mlx *mlx);

/* checking_map.c */
void	check_map(t_mlx *mlx, char **args);
void	check_arg(char	*line, t_mlx *mlx);
void	ft_count_and_check_args(char c, t_mlx *mlx);
void	check_flag(t_mlx *mlx);

/* path_validdation.c */
void	valide_path(t_mlx *mlx);
void	flood_fill(char **map_copy, int x, int y, t_flood *flood);
char	**copy_map(char **original, t_mlx *mlx);
int		find_player_position(char **map, int *x, int *y);

/* exit_error_clear.c */
void	ft_error(char *msg, t_mlx *mlx);
void	clean_struct(t_mlx *mlx);
void	free_arays(char	**aray);
int		close_window(t_mlx *mlx);

/* player_move.c */
void	player_move(t_mlx *mlx, int move);
bool	can_move(t_mlx *mlx, int x, int y);
void	exec_move(t_mlx *mlx, int x, int y);
void	handle_tile(t_mlx *mlx, int x, int y);

#endif