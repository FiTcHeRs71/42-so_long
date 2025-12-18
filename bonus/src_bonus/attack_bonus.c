
#include "../include_bonus/so_long_bonus.h"

void	player_attack(t_mlx *mlx)
{
	int	target_x;
	int	target_y;

	target_x = mlx->player.x;
	target_y = mlx->player.y;
	if (mlx->player.direction == UP)
		target_y--;
	else if (mlx->player.direction == DOWN)
		target_y++;
	else if (mlx->player.direction == LEFT)
		target_x--;
	else if (mlx->player.direction == RIGHT)
		target_x++;
	if(target_x < 0 || target_y < 0 || !mlx->args[target_x] || !mlx->args[target_y])
	{
		return;
	}
	mlx->player.is_attacking = 1;
	check_attack_hit(mlx, target_x, target_y);
}
void	check_attack_hit(t_mlx *mlx, int target_x, int target_y)
{
	int	i;

	i = 0;
	while (i < mlx->game.enemy_count)
	{
		if (mlx->game.enemies[i].is_alive && mlx->game.enemies[i].x == target_x
			&& mlx->game.enemies[i].y == target_y)
			{
				kill_enemy(mlx, i);
				return;
			}
		i++;
	}
	ft_printf("💨 Failed throw, maybe next time\n");
}
void	kill_enemy(t_mlx *mlx, int enemy_index)
{
	int	x;
	int	y;

	x = mlx->game.enemies[enemy_index].x;
	y = mlx->game.enemies[enemy_index].y;
	mlx->game.enemies[enemy_index].is_alive = 0;
	mlx->args[y][x] = '0';
	ft_printf("TUTUDUDU You are a pure dresser, you will catch'em all.\n");
	set_up_map(mlx);
}
void	trigger_game_over(t_mlx *mlx)
{
ft_printf("\n");
	ft_printf("**************************************\n");
	ft_printf("*         💀 GAME OVER 💀            *\n");
	ft_printf("*       You have been defeated!      *\n");
	ft_printf("*         Press ESC to quit          *\n");
	ft_printf("**************************************\n");
	mlx->game.state = STATE_GAME_OVER;
	mlx_destroy_window(mlx->mlx_connect, mlx->mlx_window);
	mlx->mlx_window = mlx_new_window(mlx->mlx_connect, 1000, 1300,
			"Game Over - So_long");
	if (!mlx->mlx_window)
		ft_error("Unable to create game over window\n", mlx);
	mlx_hook(mlx->mlx_window, 2, 1L << 0, handle_keyboard_bonus, mlx);
	mlx_hook(mlx->mlx_window, 17, 0, close_window, mlx);
	mlx_clear_window(mlx->mlx_connect, mlx->mlx_window);
	mlx_put_image_to_window(mlx->mlx_connect, mlx->mlx_window, mlx->tex.game_over, 0, 0);
}
