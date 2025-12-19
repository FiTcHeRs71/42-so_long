/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:26:34 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/19 10:28:16 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	maj_enemy_struct(t_mlx *mlx, int index, int x, int y)
{
	mlx->game.enemies[index].y = y;
	mlx->game.enemies[index].start_x = x;
	mlx->game.enemies[index].start_y = y;
	mlx->game.enemies[index].dir = RIGHT;
	mlx->game.enemies[index].patrol_range = 12;
	mlx->game.enemies[index].is_alive = 1;
	mlx->game.enemies[index].x = x;
	index++;
	return (index);
}

void	try_move_enemy(t_mlx *mlx, t_enemy *enemy, int *new_x)
{
	if (enemy->dir == RIGHT)
	{
		if (enemy->x - enemy->start_x < enemy->patrol_range
			&& mlx->args[enemy->y][enemy->x + 1] == '0')
			(*new_x)++;
		else
			enemy->dir = UP;
	}
	else if (enemy->dir == LEFT)
	{
		if (enemy->start_x - enemy->x < enemy->patrol_range
			&& mlx->args[enemy->y][enemy->x - 1] == '0')
			(*new_x)--;
		else
			enemy->dir = RIGHT;
	}
}

void	try_move_enemy_vertical(t_mlx *mlx, t_enemy *enemy, int *new_y)
{
	if (enemy->dir == UP)
	{
		if (enemy->start_y - enemy->y < enemy->patrol_range
			&& mlx->args[enemy->y - 1][enemy->x] == '0')
			(*new_y)--;
		else
			enemy->dir = DOWN;
	}
	else if (enemy->dir == DOWN)
	{
		if (enemy->y - enemy->start_y < enemy->patrol_range
			&& mlx->args[enemy->y + 1][enemy->x] == '0')
			(*new_y)++;
		else
			enemy->dir = LEFT;
	}
}
