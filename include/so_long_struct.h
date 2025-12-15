#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H

typedef enum	s_move
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
}	t_move;

typedef struct s_tex
{
	void	*tree;
	void	*grass;
	void	*player;
	void	*esc;
	void	*eat;
	int		width;
	int		height;

}	t_tex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bits;
	int		endlian;
	int		len;
}			t_img;

	typedef struct s_window
{
	int			size_x;
	int			size_y;
}				t_window;

typedef struct s_game
{
	int			count;
}		t_game;

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
}				t_mlx;

typedef struct s_flood
{
	int			collectibles_found;
	int			exit_found;
}				t_flood;

#endif