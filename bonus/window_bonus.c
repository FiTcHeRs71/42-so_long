
#include "../include/so_long.h"

#include "../include/so_long.h"

void	handle_window_bonus(t_mlx *mlx)
{
	mlx->mlx_connect = mlx_init();
	if (!mlx->mlx_connect)
		ft_error("Unable to init connection\n", mlx);
	mlx->mlx_window = mlx_new_window(mlx->mlx_connect, mlx->window.size_x,
			mlx->window.size_y, "Fitch > Leo sur MK");
	if (!mlx->mlx_window)
		ft_error("Unable to create new window\n", mlx);
	mlx_loop_hook(mlx->mlx_connect, game_loop, mlx);
	mlx_hook(mlx->mlx_window, 2, 1L << 0, handle_keyboard_bonus, mlx);
	mlx_hook(mlx->mlx_window, 17, 0, close_window, mlx);
}