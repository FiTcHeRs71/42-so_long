
#include "../include_bonus/so_long_bonus.h"

void	handle_tile(t_mlx *mlx, int x, int y)
{
	char	tile;

	tile = mlx->args[y][x];
	if (tile == 'C')
	{
		mlx->game.food++;
		mlx->args[y][x] = '0';
		ft_printf("Collected !(%d/%d)\n", mlx->game.food, mlx->flag_c);
	}
	else if (tile == 'E' && mlx->game.food == mlx->flag_c)
	{
		ft_printf("*====================================*\n");
		ft_printf("*                                    *\n");
		ft_printf("*             VICTORY                *\n");
		ft_printf("*     You did this with %d moves.    *\n", mlx->game.way);
		ft_printf("*Wanna try other maps or less moves ?*\n");
		ft_printf("*====================================*\n");
		close_window(mlx);
	}
}

void	exec_move(t_mlx *mlx, int x, int y)
{
	mlx->args[mlx->game.y][mlx->game.x] = '0';
	handle_tile(mlx, x, y);
	mlx->game.x = x;
	mlx->game.y = y;
	mlx->args[y][x] = 'P';
	ft_printf("Moves : %d\n", mlx->game.count);
	set_up_map(mlx);
}

bool	can_move(t_mlx *mlx, int x, int y)
{
	char	target;

	target = mlx->args[y][x];
	if ((x < 0 || y < 0) || (!mlx->args[y] || !mlx->args[y][x]))
	{
		return (false);
	}
	if (target == '1')
	{
		ft_printf("Come on... you dont see the wall ?\n");
		return (false);
	}
	if (target == 'E' && mlx->game.food < mlx->flag_c)
	{
		ft_printf("You must take all food before leave\n");
		return (false);
	}
	return (true);
}

void	player_move(t_mlx *mlx, int move)
{
	if (move == UP)
		mlx->player.y--;
	else if (move == DOWN)
		mlx->player.y++;
	else if (move == LEFT)
		mlx->player.x--;
	else if (move == RIGHT)
		mlx->player.x++;
	mlx->game.x = mlx->player.x;
	mlx->game.y = mlx->player.y;
	mlx->game.way++;
	ft_printf("Steps: %d\n", mlx->game.way);
	if (can_move(mlx, mlx->player.x, mlx->player.y))
		exec_move(mlx, mlx->player.x, mlx->player.y);
}

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
