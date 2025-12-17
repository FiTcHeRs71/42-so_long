
#include "../include_bonus/so_long_bonus.h"

void	*load_sprite(t_mlx *mlx, char *path)
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(mlx->mlx_connect, path, &w, &h);
	if (!img)
	{
		ft_error("Error : Failed to load sprite\n", mlx);
	}
	return (img);
}

char	*build_sprite_path(t_mlx *mlx, char *dir, int frame)
{
	char	*tmp1;
	char	*tmp2;
	char	*frame_str;
	char	*path;

	tmp1 = ft_strjoin("bonus/texture_bonus/player/", dir);
	tmp2 = ft_strjoin(tmp1, "_");
	free(tmp1);
	frame_str = ft_itoa(frame);
	tmp1 = ft_strjoin(tmp2, frame_str);
	free(tmp2);
	free(frame_str);
	path = ft_strjoin(tmp1, ".xpm");
	free(tmp1);
	if (!path)
		ft_error("Malloc failed.\n", mlx);
	return (path);
}
void	init_animation(t_animation *anim)
{
	anim->frames = ft_calloc(3, sizeof(void *));
	if (!anim->frames)
	{
		return ;
	}
	anim->frame_count = 3;
	anim->current_frame = 0;
	anim->frame_delay = 6;
	anim->tick_counter = 0;
}
void	load_dir_frames(t_mlx *mlx, int move, char *dir)
{
	char	*path;
	int		i;

	init_animation(&mlx->player.anim[move]);
	if (!mlx->player.anim[move].frames)
		ft_error("Malloc failed.\n", mlx);
	i = 0;
	while (i < 3)
	{
		path = build_sprite_path(mlx, dir, i);
		mlx->player.anim[move].frames[i] = load_sprite(mlx, path);
		free(path);
		i++;
	}
}
void	load_player_animations(t_mlx *mlx)
{
	load_dir_frames(mlx, DOWN, "down");
	load_dir_frames(mlx, UP, "up");
	load_dir_frames(mlx, LEFT, "left");
	load_dir_frames(mlx, RIGHT, "right");
	mlx->player.direction = DOWN;
	mlx->player.is_moving = 0;
}
