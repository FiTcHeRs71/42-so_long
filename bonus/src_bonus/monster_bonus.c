
#include "../include_bonus/so_long_bonus.h"

void	update_enemy(t_mlx *mlx)
{
	static int	frame_counter;
	int			i;

	if(frame_counter == 0)
	{
		frame_counter = 1;
	}
	frame_counter++;
	if (frame_counter < 30)
		return ;
	frame_counter = 0;
	i = 0;
	while (i < mlx->game.enemy_count)
	{
		if (mlx->game.enemies[i].is_alive)
			move_enemy(mlx, &mlx->game.enemies[i]);
		i++;
	}
}

void	move_enemy(t_mlx *mlx, t_enemy *enemy) // a check avec attk
{
	int	new_x;
	int	new_y;

	new_x = enemy->x;
	new_y = enemy->y;
	if (enemy->dir == RIGHT)
	{
		if (enemy->x - enemy->start_x < enemy->patrol_range
			&& mlx->args[enemy->y][enemy->x + 1] == '0')
			new_x++;
		else
			enemy->dir = LEFT;
	}
	else if (enemy->dir == LEFT)
	{
		if (enemy->start_x - enemy->x < enemy->patrol_range
			&& mlx->args[enemy->y][enemy->x - 1] == '0')
			new_x--;
		else
			enemy->dir = UP;
	}
	else if (enemy->dir == UP)
	{
		if (enemy->start_y - enemy->y < enemy->patrol_range
			&& mlx->args[enemy->y - 1][enemy->x] == '0')
			new_y--;
		else
			enemy->dir = DOWN;
	}
	else if (enemy->dir == DOWN)
	{
		if (enemy->y - enemy->start_y < enemy->patrol_range
			&& mlx->args[enemy->y + 1][enemy->x] == '0')
			new_y++;
		else
			enemy->dir = RIGHT;
	}
	if (new_x != enemy->x || new_y != enemy->y)
	{
		mlx->args[enemy->y][enemy->x] = '0';
		enemy->x = new_x;
		enemy->y = new_y;
		mlx->args[new_y][new_x] = 'M';
	}
}

void	init_enemy(t_mlx *mlx)
{
	int	y;
	int	x;
	int	index;

	if(mlx->game.enemy_count == 0)
		return;
	mlx->game.enemies = ft_calloc(mlx->game.enemy_count, sizeof(t_enemy));
	if (!mlx->game.enemies)
		ft_error("Unable to allocate memory\n", mlx);
	index = 0;
	y = 0;
	while (mlx->args[y])
	{
		x = 0;
		while(mlx->args[y][x])
		{
			if (mlx->args[y][x] == 'M')
			{
				mlx->game.enemies[index].x = x;
				mlx->game.enemies[index].y = y;
				mlx->game.enemies[index].start_x = x;
				mlx->game.enemies[index].start_y = y;
				mlx->game.enemies[index].dir = RIGHT;
				mlx->game.enemies[index].patrol_range = 3;
				mlx->game.enemies[index].is_alive = 1;
				index++;
			}
			x++;
		}
		y++;
	}
}

void	*get_enemy_sprite(t_mlx *mlx, int dir)
{
	if (dir == UP)
	{
		return (mlx->tex.enemy_up);
	}
	else if (dir == DOWN)
	{
		return (mlx->tex.enemy_down);
	}
	else if (dir == LEFT)
	{
		return (mlx->tex.enemy_left);
	}
	else
	{
		return (mlx->tex.enemy_right);
	}
}

void	render_enemy(t_mlx *mlx)
{
	int		i;
	void	*sprite;

	i = 0;
	while(i < mlx->game.enemy_count)
	{
		if(mlx->game.enemies[i].is_alive)
		{
			sprite = get_enemy_sprite(mlx, mlx->game.enemies[i].dir);
			mlx_put_image_to_window(mlx->mlx_connect, mlx->mlx_window, sprite, mlx->game.enemies[i].x * 64, mlx->game.enemies[i].y * 64);
		}
		i++;
	}
}