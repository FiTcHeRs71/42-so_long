
#include "../include/so_long_bonus.h"

void	next_frame_cycle(t_mlx *mlx, int *next_frame)
{
	if(mlx->anim.current_frame == 0)
	{
		mlx->anim.current_frame = (*next_frame == 1) ? 2 : 1;
	}
	mlx->anim.tick_counter = 0;
}
void	update_player_animation(t_mlx *mlx)
{
	static int next;
	t_move dir;
	t_animation *anim;

	next = 1;
	dir = mlx->player.direction;
	anim = &mlx->player.anim[dir];
	if (!mlx->player.is_moving)
	{
		anim->current_frame = 0;
		anim->tick_counter = 0;
		return; //ft_error ?
	}
	anim->tick_counter++;
	if (anim->tick_counter >= anim->frame_delay)
	{
		next_frame_cycle(mlx, &next);
	}
}

void	render_player(t_mlx *mlx)
{
	t_move		dir;
	t_animation *anim;
	void 		*sprite;
	int			x;
	int			y;

	dir = mlx->player.direction;
	anim = &mlx->player.anim[dir];
	sprite = mlx->anim.frames[anim->current_frame];
	x = mlx->player.x * 64;
	y = mlx->player.y * 64;
	mlx_put_image_to_window(mlx->mlx_connect, mlx->mlx_window, sprite, x, y);
}