/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:18:59 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/16 18:18:59 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_game		game;

	if (argc != 2)
	{
		ft_printf("ERROR\n");
		ft_printf("Usage ./so_long <valid map> ");
		return (0);
	}
	ft_memset(&mlx, 0, sizeof(mlx));
	ft_memset(&game, 0, sizeof(game));
	init_data(&mlx, argv);
	handle_window(&mlx);
	load_textures(&mlx);
	init_player(&mlx);
	mlx_loop(mlx.mlx_connect);
	return (0);
}
