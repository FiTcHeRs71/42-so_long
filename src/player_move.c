/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:07:26 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/16 19:07:26 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_move(t_mlx *mlx, int move)
{
	int	new_x;
	int	new_y;

	new_x = mlx->game.x;
	new_y = mlx->game.y;
	if (move == UP)
	{
		new_y--;
	}
	else if (move == DOWN)
	{
		new_y++;
	}
	else if (move == RIGHT)
	{
		new_x++;
	}
	else if (move == LEFT)
	{
		new_x--;
	}
	mlx->game.way = move;
	if (can_move(mlx, new_x, new_y))
		exec_move(mlx, new_x, new_y);
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

void	exec_move(t_mlx *mlx, int x, int y)
{
	mlx->game.count++;
	mlx->args[mlx->game.y][mlx->game.x] = '0';
	handle_tile(mlx, x, y);
	mlx->game.x = x;
	mlx->game.y = y;
	mlx->args[y][x] = 'P';
	ft_printf("Moves : %d\n", mlx->game.count);
	set_up_map(mlx);
}

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
		ft_printf("*     You did this with %d moves.    *\n", mlx->game.count);
		ft_printf("*Wanna try other maps or less moves ?*\n");
		ft_printf("*====================================*\n");
		close_window(mlx);
	}
}
