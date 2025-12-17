
#include "../include/so_long.h"

void	next_frame_cycle(t_animation *anim, int *next_frame)
{
	if (anim->current_frame == 0)
	{
		if (*next_frame == 1)
			anim->current_frame = 2;
		else
			anim->current_frame = 1;
	}
	anim->tick_counter = 0;
}
void	update_player_animation(t_mlx *mlx)
{
	static int	next;
	t_move		dir;
	t_animation	*anim;

	if (next == 0)
	{
		next = 1;
	}
	dir = mlx->player.direction;
	anim = &mlx->player.anim[dir];
	if (!mlx->player.is_moving)
	{
		anim->current_frame = 0;
		anim->tick_counter = 0;
		return ;
	}
	anim->tick_counter++;
	if (anim->tick_counter >= anim->frame_delay)
	{
		next_frame_cycle(anim, &next);
		render_player(mlx);
	}
}

void	render_player(t_mlx *mlx)
{
	t_move		dir;
	t_animation	*anim;
	void		*sprite;
	int			x;
	int			y;

	dir = mlx->player.direction;
	anim = &mlx->player.anim[dir];
	sprite = anim->frames[anim->current_frame];
	x = mlx->player.x * 64;
	y = mlx->player.y * 64;
	mlx_put_image_to_window(mlx->mlx_connect, mlx->mlx_window, sprite, x, y);
}
