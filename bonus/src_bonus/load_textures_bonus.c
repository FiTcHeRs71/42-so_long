/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:23:30 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/18 16:23:47 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	load_textures(t_mlx *mlx)
{
	mlx->tex.tree = mlx_xpm_file_to_image(mlx->mlx_connect, "texture/tree.xpm",
			&mlx->tex.width, &mlx->tex.height);
	if (!mlx->tex.tree)
		ft_error("Unable to find tree.xpm.\n", mlx);
	mlx->tex.player = mlx_xpm_file_to_image(mlx->mlx_connect,
			"bonus/texture_bonus/player/down_0.xpm", &mlx->tex.width,
			&mlx->tex.height);
	if (!mlx->tex.player)
		ft_error("Unable to find player.xpm.\n", mlx);
	mlx->tex.esc = mlx_xpm_file_to_image(mlx->mlx_connect, "texture/esc.xpm",
			&mlx->tex.width, &mlx->tex.height);
	if (!mlx->tex.esc)
		ft_error("Unable to find esc.xpm.\n", mlx);
	mlx->tex.eat = mlx_xpm_file_to_image(mlx->mlx_connect, "texture/eat.xpm",
			&mlx->tex.width, &mlx->tex.height);
	if (!mlx->tex.eat)
		ft_error("Unable to find eat.xpm.\n", mlx);
	mlx->tex.grass = mlx_xpm_file_to_image(mlx->mlx_connect,
			"texture/grass.xpm", &mlx->tex.width, &mlx->tex.height);
	if (!mlx->tex.grass)
		ft_error("Unable to find grass.xpm.\n", mlx);
	load_hp_textures(mlx);
}

void	load_enemy(t_mlx *mlx)
{
	mlx->tex.enemy_down = mlx_xpm_file_to_image(mlx->mlx_connect,
			"bonus/texture_bonus/monster/monster_D.xpm", &mlx->tex.width,
			&mlx->tex.height);
	if (!mlx->tex.enemy_down)
		ft_error("Unable to find monster_D.xpm\n", mlx);
	mlx->tex.enemy_up = mlx_xpm_file_to_image(mlx->mlx_connect,
			"bonus/texture_bonus/monster/monster_U.xpm", &mlx->tex.width,
			&mlx->tex.height);
	if (!mlx->tex.enemy_up)
		ft_error("Unable to find monster_U.xpm\n", mlx);
	mlx->tex.enemy_left = mlx_xpm_file_to_image(mlx->mlx_connect,
			"bonus/texture_bonus/monster/monster_L.xpm", &mlx->tex.width,
			&mlx->tex.height);
	if (!mlx->tex.enemy_left)
		ft_error("Unable to find monster_L.xpm\n", mlx);
	mlx->tex.enemy_right = mlx_xpm_file_to_image(mlx->mlx_connect,
			"bonus/texture_bonus/monster/monster_R.xpm", &mlx->tex.width,
			&mlx->tex.height);
	if (!mlx->tex.enemy_right)
		ft_error("Unable to find monster_R.xpm\n", mlx);
	mlx->tex.game_over = mlx_xpm_file_to_image(mlx->mlx_connect,
			"bonus/texture_bonus/gm.xpm", &mlx->tex.width, &mlx->tex.height);
	if (!mlx->tex.game_over)
		ft_error("Unable to find gm.xpm\n", mlx);
}

void	load_hp_textures(t_mlx *mlx)
{
	mlx->tex.hp_1 = mlx_xpm_file_to_image(mlx->mlx_connect,
			"bonus/texture_bonus/1hp.xpm", &mlx->tex.width, &mlx->tex.height);
	if (!mlx->tex.hp_1)
		ft_error("Unable to find 1hp.xpm.\n", mlx);
	mlx->tex.hp_2 = mlx_xpm_file_to_image(mlx->mlx_connect,
			"bonus/texture_bonus/2hp.xpm", &mlx->tex.width, &mlx->tex.height);
	if (!mlx->tex.hp_2)
		ft_error("Unable to find 2hp.xpm.\n", mlx);
	mlx->tex.hp_3 = mlx_xpm_file_to_image(mlx->mlx_connect,
			"bonus/texture_bonus/3hp.xpm", &mlx->tex.width, &mlx->tex.height);
	if (!mlx->tex.hp_3)
		ft_error("Unable to find 3hp.xpm.\n", mlx);
}

void	init_player(t_mlx *mlx)
{
	int	y;
	int	x;

	mlx->player.direction = DOWN;
	mlx->player.is_moving = 0;
	mlx->player.is_attacking = 0;
	mlx->player.hp = 3;
	y = 0;
	while (mlx->args[y])
	{
		x = 0;
		while (mlx->args[y][x])
		{
			if (mlx->args[y][x] == 'P')
			{
				mlx->player.x = x;
				mlx->player.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}
