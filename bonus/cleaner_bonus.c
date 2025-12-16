
#include "../include/so_long.h"

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
