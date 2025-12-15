
#include "../include/so_long.h"

void	handle_window(t_mlx *mlx)
{
	mlx->mlx_connect = mlx_init();
	if (!mlx->mlx_connect)
	{
		ft_error("Unable to init connection\n", mlx);
	}
	mlx->mlx_window = mlx_new_window(mlx->mlx_connect, mlx->window.size_x, mlx->window.size_y, "Fitch > Leo sur MK");
	if (!mlx->mlx_window)
	{
		ft_error("Unable to create new window\n", mlx);
	}
	mlx_key_hook(mlx->mlx_window, handle_keyboard_input, mlx);
	mlx_hook(mlx->mlx_window, 17, 0, close_window, mlx);
}
int	handle_keyboard_input(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
	{	
		ft_printf("%d Esc pressed - closing window\n", keycode);
		close_window(mlx);
	}
	if (keycode == XK_w || keycode == XK_Up)
	{
		player_mouv(mlx, UP);
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		player_mouv(mlx, LEFT);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		player_mouv(mlx, DOWN);
	}
		if (keycode == XK_d || keycode == XK_Right)
	{
		player_mouv(mlx, RIGHT);
	}
	ft_printf("You already have done %d mooves", mlx->game.count);
	return (0);
}

