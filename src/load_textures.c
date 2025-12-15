
#include "../include/so_long.h"

void	load_textures(t_mlx *mlx)
{
	mlx->tex.grass = mlx_xpm_file_to_image(mlx->mlx_connect, "texture/grass.xpm", &mlx->tex.width, &mlx->tex.height);
	if (!mlx->tex.grass)
	{
		ft_error("Unable to find grass.xpm.\n", mlx);
	}
	mlx->tex.tree = mlx_xpm_file_to_image(mlx->mlx_connect, "texture/tree.xpm", &mlx->tex.width, &mlx->tex.height);
	if (!mlx->tex.tree)
	{
		ft_error("Unable to find tree.xpm.\n", mlx);
	}
	mlx->tex.player = mlx_xpm_file_to_image(mlx->mlx_connect, "texture/player.xpm", &mlx->tex.width, &mlx->tex.height);
		if (!mlx->tex.player)
	{
		ft_error("Unable to find player.xpm.\n", mlx);
	}
	mlx->tex.esc = mlx_xpm_file_to_image(mlx->mlx_connect, "texture/esc.xpm", &mlx->tex.width, &mlx->tex.height);
	if (!mlx->tex.esc)
	{
		ft_error("Unable to find esc.xpm.\n", mlx);
	}
	mlx->tex.eat= mlx_xpm_file_to_image(mlx->mlx_connect, "texture/eat.xpm", &mlx->tex.width, &mlx->tex.height);
		if (!mlx->tex.eat)
	{
		ft_error("Unable to find eat.xpm.\n", mlx);
	}
}
