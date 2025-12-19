/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:51:14 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/18 14:51:24 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_BONUS_H
# define SO_LONG_STRUCT_BONUS_H

typedef enum e_state
{
	STATE_MENU,
	STATE_GAME,
	STATE_GAME_OVER,
	STATE_WIN
}				t_state;

typedef enum s_move
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
}				t_move;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			start_x;
	int			start_y;
	int			dir;
	int			is_alive;
	int			patrol_range;
}				t_enemy;

typedef struct s_animation
{
	void		**frames;
	int			frame_count;
	int			current_frame;
	int			tick_counter;
	int			frame_delay;
}				t_animation;

typedef struct s_player
{
	int			x;
	int			y;
	t_move		direction;
	int			is_moving;
	int			hp;
	int			is_attacking;
	t_animation	anim[4];
}				t_player;

typedef struct s_tex
{
	void		*tree;
	void		*grass;
	void		*player;
	void		*esc;
	void		*menu;
	void		*eat;
	void		*game_over;
	void		*enemy_up;
	void		*enemy_down;
	void		*enemy_left;
	void		*enemy_right;
	void		*hp_3;
	void		*hp_2;
	void		*hp_1;
	int			width;
	int			height;

}				t_tex;

typedef struct s_img
{
	void		*img_ptr;
	char		*pxl_ptr;
	int			bits;
	int			endian;
	int			len;
}				t_img;

typedef struct s_window
{
	int			size_x;
	int			size_y;
}				t_window;

typedef struct s_game
{
	t_state		state;
	int			moves;
	int			food;
	int			total_food;
	t_enemy		*enemies;
	int			enemy_count;
}				t_game;

typedef struct s_mlx
{
	void		*mlx_connect;
	void		*mlx_window;
	int			len;
	char		**args;
	int			flag_e;
	int			flag_p;
	int			flag_c;
	t_window	window;
	t_img		img;
	t_tex		tex;
	t_game		game;
	t_player	player;
}				t_mlx;

typedef struct s_flood
{
	int			collectibles_found;
	int			exit_found;
}				t_flood;

#endif