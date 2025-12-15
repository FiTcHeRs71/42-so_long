
#include "../include/so_long.h"

void	free_arays(char	**aray)
{
	size_t	i;

	i = 0;
	while (aray[i])
	{
		free(aray[i]);
		i++;
	}
	free (aray);
}

void	clean_struct(t_mlx *mlx)
{
	if (mlx && mlx->args)
	{
		free_arays(mlx->args);
	}
}

void	ft_error(char *msg, t_mlx *mlx)
{
	ft_putstr_fd(msg, 2);
	close_window(mlx);
}
int	close_window(t_mlx *mlx)
{
	if (mlx && mlx->mlx_connect && mlx->tex.eat)
		mlx_destroy_image(mlx->mlx_connect, mlx->tex.eat);
	if (mlx && mlx->mlx_connect && mlx->tex.esc)
		mlx_destroy_image(mlx->mlx_connect, mlx->tex.esc);
	if (mlx && mlx->mlx_connect && mlx->tex.tree)
		mlx_destroy_image(mlx->mlx_connect, mlx->tex.tree);
	if (mlx && mlx->mlx_connect && mlx->tex.player)
		mlx_destroy_image(mlx->mlx_connect, mlx->tex.player);
	if (mlx && mlx->mlx_connect && mlx->tex.grass)
		mlx_destroy_image(mlx->mlx_connect, mlx->tex.grass);
	if (mlx && mlx->mlx_connect && mlx->mlx_window)
		mlx_destroy_window(mlx->mlx_connect, mlx->mlx_window);
	if (mlx && mlx->mlx_connect)
	{
		mlx_destroy_display(mlx->mlx_connect);
		free(mlx->mlx_connect);
	}
	clean_struct(mlx);
	exit(EXIT_SUCCESS);
}
