
#include "../include/so_long.h"

int	handle_keyboard_bonus(int keycode, t_mlx *mlx)
{
	t_move	direction;

	if (keycode == XK_Escape)
		close_window(mlx);
	if (keycode == XK_w || keycode == XK_Up)
		direction = UP;
	else if (keycode == XK_a || keycode == XK_Left)
		direction = LEFT;
	else if (keycode == XK_s || keycode == XK_Down)
		direction = DOWN;
	else if (keycode == XK_d || keycode == XK_Right)
		direction = RIGHT;
	else
		return (0);
	mlx->player.direction = direction;
	mlx->player.is_moving = 1;
	
	player_move(mlx, direction);
	return (0);
}
int	game_loop(t_mlx *mlx)
{
	update_player_animation(mlx);
	return (0);
}
void	handle_hook(t_mlx *mlx)
{
	mlx_loop_hook(mlx->mlx_connect, game_loop, &mlx);
	mlx_hook(mlx->mlx_window, 2, 1L << 0, handle_keyboard_bonus, &mlx);
	mlx_hook(mlx->mlx_window, 17, 0, close_window, &mlx);
}