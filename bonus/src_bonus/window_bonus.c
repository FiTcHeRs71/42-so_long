
#include "../include/so_long.h"

int	handle_keyrelease(int keycode, t_mlx *mlx)
{
	(void)keycode;
	mlx->player.is_moving = 0;
	mlx->player.anim[mlx->player.direction].current_frame = 0;
	render_player(mlx);
	return (0);
}

void	handle_window_bonus(t_mlx *mlx)
{
	mlx->mlx_connect = mlx_init();
	if (!mlx->mlx_connect)
		ft_error("Unable to init connection\n", mlx);
	mlx->mlx_window = mlx_new_window(mlx->mlx_connect, mlx->window.size_x,
			mlx->window.size_y, "So_long | bonus");
	if (!mlx->mlx_window)
		ft_error("Unable to create new window\n", mlx);
	mlx_loop_hook(mlx->mlx_connect, game_loop, mlx);
	mlx_hook(mlx->mlx_window, 2, 1L << 0, handle_keyboard_bonus, mlx);
	mlx_hook(mlx->mlx_window, 3, 1L << 1, handle_keyrelease, mlx);
	mlx_hook(mlx->mlx_window, 17, 0, close_window, mlx);
}