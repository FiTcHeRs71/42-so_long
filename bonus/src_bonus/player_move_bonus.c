
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
		ft_printf("*     You did this with %d moves.    *\n", mlx->game.moves);
		ft_printf("*Wanna try other maps or less moves ?*\n");
		ft_printf("*====================================*\n");
		close_window(mlx);
	}
}

void	exec_move(t_mlx *mlx, int new_x, int new_y)
{
	mlx->args[mlx->player.y][mlx->player.x] = '0';
	handle_tile(mlx, new_x, new_y);
	mlx->player.x = new_x;
	mlx->player.y = new_y;
	mlx->args[new_y][new_x] = 'P';
	mlx->game.moves++;
	ft_printf("Moves : %d\n", mlx->game.moves);
	set_up_map(mlx);
}

bool	can_move(t_mlx *mlx, int x, int y)
{
	char	target;

	target = mlx->args[y][x];
	if ((x < 0 || y < 0) || (!mlx->args[y] || !mlx->args[y][x]))
		return (false);
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
	if (target == 'M')
	{
		mlx->player.hp -= 1;
		ft_printf("charizard used fire blast, you lose 1 HP 💔\n");
		if (mlx->player.hp <= 0)
			trigger_game_over(mlx);
		return(false);
	}
	return (true);
}

void	player_move(t_mlx *mlx, int move)
{
	int	new_x;
	int	new_y;

	new_x = mlx->player.x;
	new_y = mlx->player.y;
	if (move == UP)
		new_y--;
	else if (move == DOWN)
		new_y++;
	else if (move == LEFT)
		new_x--;
	else if (move == RIGHT)
		new_x++;
	mlx->player.direction = move;
	if (can_move(mlx, new_x, new_y))
	{
		mlx->player.is_moving = 1;
		exec_move(mlx, new_x, new_y);
	}
}

int	handle_keyboard_bonus(int keycode, t_mlx *mlx)
{
	if(mlx->game.state == STATE_MENU)
	{
		handle_menu_keys(keycode, mlx);
	}
	else if (mlx->game.state == STATE_GAME)
	{
		if (keycode == XK_Escape)
			close_window(mlx);
		if (keycode == XK_w || keycode == XK_Up)
			player_move(mlx, UP);
		else if (keycode == XK_a || keycode == XK_Left)
			player_move(mlx, LEFT);
		else if (keycode == XK_s || keycode == XK_Down)
			player_move(mlx, DOWN);
		else if (keycode == XK_d || keycode == XK_Right)
			player_move(mlx, RIGHT);
		else if (keycode == XK_space)
			player_attack(mlx);
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
		update_enemy(mlx);
		set_up_map(mlx);
		update_player_animation(mlx);
	}
	return (0);
}
