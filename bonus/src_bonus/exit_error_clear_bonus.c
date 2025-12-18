
#include "../include_bonus/so_long_bonus.h"

void	free_arays(char **aray)
{
	size_t	i;

	i = 0;
	while (aray[i])
	{
		free(aray[i]);
		i++;
	}
	free(aray);
}

void	clean_struct(t_mlx *mlx)
{
	if (mlx && mlx->args)
	{
		free_arays(mlx->args);
	}
	if (mlx && mlx->game.enemies)
	{
		free(mlx->game.enemies);
	}
}

void	ft_error(char *msg, t_mlx *mlx)
{
	ft_putstr_fd(msg, 2);
	close_window(mlx);
}

void	free_image(t_mlx *mlx)
{
	if (mlx && mlx->mlx_connect && mlx->tex.enemy_down)
		mlx_destroy_image(mlx->mlx_connect, mlx->tex.enemy_down);
	if (mlx && mlx->mlx_connect && mlx->tex.enemy_right)
		mlx_destroy_image(mlx->mlx_connect, mlx->tex.enemy_right);
	if (mlx && mlx->mlx_connect && mlx->tex.enemy_left)
		mlx_destroy_image(mlx->mlx_connect, mlx->tex.enemy_left);
	if (mlx && mlx->mlx_connect && mlx->tex.enemy_up)
		mlx_destroy_image(mlx->mlx_connect, mlx->tex.enemy_up);
	if (mlx && mlx->mlx_connect && mlx->tex.hp_1)
		mlx_destroy_image(mlx->mlx_connect, mlx->tex.hp_1);
	if (mlx && mlx->mlx_connect && mlx->tex.hp_2)
		mlx_destroy_image(mlx->mlx_connect, mlx->tex.hp_2);
	if (mlx && mlx->mlx_connect && mlx->tex.hp_3)
		mlx_destroy_image(mlx->mlx_connect, mlx->tex.hp_3);
}

int	close_window(t_mlx *mlx)
{
	free_image(mlx);
	if (mlx->player.anim[0].frames)
		free_player_animations(mlx);
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
void	free_player_animations(t_mlx *mlx)
{
	int	dir;
	int	i;

	dir = 0;
	while (dir < 4)
	{
		i = 0;
		while ( i < 3)
		{
			if(mlx->player.anim[dir].frames[i])
			{
				mlx_destroy_image(mlx->mlx_connect, mlx->player.anim[dir].frames[i]);
			}
			mlx->player.anim[dir].frames[i] = NULL;
			i++;
		}
		if(mlx->player.anim[dir].frames)
		{
			free(mlx->player.anim[dir].frames);
			mlx->player.anim[dir].frames = NULL;
		}
		dir++;
	}
}