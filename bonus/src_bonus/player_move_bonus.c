
#include "../include_bonus/so_long_bonus.h"

int	handle_keyboard_bonus(int keycode, t_mlx *mlx)
{
	t_move	direction;

	if(mlx->game.state == STATE_MENU)
	{
		handle_menu_keys(keycode, mlx);
	}
	else if (mlx->game.state == STATE_GAME)
	{
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
		mlx->player.x = mlx->game.x;
		mlx->player.y = mlx->game.y;
	}
	return (0);
}
int	game_loop(t_mlx *mlx)
{
	if (mlx->game.state == STATE_MENU)
	{
		render_menu(mlx);
	}
	else if (mlx->game.state == STATE_GAME)
	{
		update_player_animation(mlx);
		render_player(mlx);
	}
	return (0);
}
