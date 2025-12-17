
#include "../include_bonus/so_long_bonus.h"

void	render_menu(t_mlx *mlx)
{
	int	center_x;
	int	center_y;
	int	color;

	color = 0xFFFFFF;
	center_x = mlx->window.size_x  / 2 -100;
	center_y = mlx->window.size_y / 2;
	mlx_clear_window(mlx->mlx_connect, mlx->mlx_window);
	mlx_string_put(mlx->mlx_connect, mlx->mlx_window, center_x, center_y -50, 0xFF0000, "== POKEMON SO_LONG ==");
	mlx_string_put(mlx->mlx_connect, mlx->mlx_window, 
		center_x, center_y, color, "Press [ENTER] to Play");
	mlx_string_put(mlx->mlx_connect, mlx->mlx_window, 
		center_x, center_y + 30, color, "Press [ESC] to Quit");
	mlx_string_put(mlx->mlx_connect, mlx->mlx_window, 
		center_x - 50, center_y + 80, 0x00FF00, "Controls: WASD to move / SPACE to Attack");
}
int	handle_menu_keys(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
	{
		close_window (mlx);
	}
	else if (keycode == XK_Return)
	{
		mlx->game.state = STATE_GAME;
		set_up_map(mlx);
	}
	return (0);
}