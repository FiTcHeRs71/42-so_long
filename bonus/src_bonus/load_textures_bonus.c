
#include "../include_bonus/so_long_bonus.h"

void	load_textures(t_mlx *mlx)
{
	mlx->tex.grass = mlx_xpm_file_to_image(mlx->mlx_connect,
			"texture/grass.xpm", &mlx->tex.width, &mlx->tex.height);
	if (!mlx->tex.grass)
		ft_error("Unable to find grass.xpm.\n", mlx);
	mlx->tex.tree = mlx_xpm_file_to_image(mlx->mlx_connect, "texture/tree.xpm",
			&mlx->tex.width, &mlx->tex.height);
	if (!mlx->tex.tree)
		ft_error("Unable to find tree.xpm.\n", mlx);
	mlx->tex.player = mlx_xpm_file_to_image(mlx->mlx_connect,
			"texture/player.xpm", &mlx->tex.width, &mlx->tex.height);
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
}

void	init_player(t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (mlx->args[y])
	{
		x = 0;
		while (mlx->args[y][x])
		{
			if (mlx->args[y][x] == 'P')
			{
				mlx->game.x = x;
				mlx->game.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
	mlx->game.player_x = mlx->game.x * 64;
	mlx->game.player_y = mlx->game.y * 64;
	mlx->game.way = 0;
}
