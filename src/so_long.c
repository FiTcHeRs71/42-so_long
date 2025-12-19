/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 09:48:58 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/19 09:48:58 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;

	if (argc != 2)
	{
		ft_printf("ERROR\n");
		ft_printf("Usage ./so_long <valid map> ");
		return (0);
	}
	ft_memset(&mlx, 0, sizeof(mlx));
	init_data(&mlx, argv);
	handle_window(&mlx);
	load_textures(&mlx);
	init_player(&mlx);
	set_up_map(&mlx);
	mlx_loop(mlx.mlx_connect);
	return (0);
}
