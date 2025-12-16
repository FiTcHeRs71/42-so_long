/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:41:51 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/16 18:42:27 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	handle_window(t_mlx *mlx)
{
	mlx->mlx_connect = mlx_init();
	if (!mlx->mlx_connect)
	{
		ft_error("Unable to init connection\n", mlx);
	}
	mlx->mlx_window = mlx_new_window(mlx->mlx_connect, mlx->window.size_x,
			mlx->window.size_y, "So_long | mandatory");
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
		player_move(mlx, UP);
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		player_move(mlx, LEFT);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		player_move(mlx, DOWN);
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		player_move(mlx, RIGHT);
	}
	return (0);
}
