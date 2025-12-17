
#ifndef SO_LONG_BONUS_STRUCT_H
# define SO_LONG_BONUS_STRUCT_H

typedef enum s_move
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
}				t_move;

typedef struct s_animation {
	void		**frames;
	int			frame_count;
	int			current_frame;
	int			tick_counter;
	int			frame_delay;
} t_animation;

typedef struct s_player {
	int			x;
	int			y;
	t_move		direction;
	int			is_moving;
	t_animation	anim[4];
} t_player;

typedef struct s_tex
{
	void		*tree;
	void		*grass;
	void		*player;
	void		*esc;
	void		*eat;
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
	int			x;
	int			y;
	int			way;
	int			food;
	int			player_x;
	int			player_y;
	int			count;
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