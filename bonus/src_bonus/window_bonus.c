/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:25:37 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/18 16:26:41 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	handle_keyrelease(int keycode, t_mlx *mlx)
{
	(void)keycode;
	mlx->player.is_moving = 0;
	mlx->player.anim[mlx->player.direction].current_frame = 0;
	render_player(mlx);
	return (0);
}

void	handle_window_bonus(t_mlx *mlx)
{
	mlx->mlx_connect = mlx_init();
	if (!mlx->mlx_connect)
		ft_error("Unable to init connection\n", mlx);
	mlx->mlx_window = mlx_new_window(mlx->mlx_connect, mlx->window.size_x,
		mlx->window.size_y, "So_long | bonus");
	if (!mlx->mlx_window)
		ft_error("Unable to create new window\n", mlx);
	mlx_loop_hook(mlx->mlx_connect, game_loop, mlx);
	mlx_hook(mlx->mlx_window, 2, 1L << 0, handle_keyboard_bonus, mlx);
	mlx_hook(mlx->mlx_window, 3, 1L << 1, handle_keyrelease, mlx);
	mlx_hook(mlx->mlx_window, 17, 0, close_window, mlx);
}

void	render_hp(t_mlx *mlx)
{
	void	*hp_texture;
	int		x;
	int		y;

	y = 0;
	x = mlx->window.size_x - 192;
	if (mlx->player.hp == 3)
	{
		hp_texture = mlx->tex.hp_3;
	}
	else if (mlx->player.hp == 2)
	{
		hp_texture = mlx->tex.hp_2;
	}
	else if (mlx->player.hp == 1)
	{
		hp_texture = mlx->tex.hp_1;
	}
	else
	{
		return ;
	}
	mlx_put_image_to_window(mlx->mlx_connect, mlx->mlx_window, hp_texture, x,
		y);
}

void	render_hud(t_mlx *mlx)
{
	render_hp(mlx);
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
	else if (mlx->game.state == STATE_GAME_OVER)
	{
	}
	return (0);
}
