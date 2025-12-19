/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_anim_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:54:15 by fducrot           #+#    #+#             */
/*   Updated: 2025/12/18 14:54:15 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	next_frame_cycle(t_animation *anim, int *next_frame)
{
	if (anim->current_frame == 0)
	{
		if (*next_frame == 1)
			anim->current_frame = 2;
		else
			anim->current_frame = 1;
		*next_frame = -(*next_frame);
	}
	else
	{
		anim->current_frame = 0;
	}
	anim->tick_counter = 0;
}

void	update_player_animation(t_mlx *mlx)
{
	static int	next;
	t_animation	*anim;

	if (next == 0)
	{
		next = 1;
	}
	anim = &mlx->player.anim[mlx->player.direction];
	if (!mlx->player.is_moving)
	{
		anim->current_frame = 0;
		anim->tick_counter = 0;
		render_player(mlx);
		return ;
	}
	anim->tick_counter++;
	if (anim->tick_counter >= anim->frame_delay)
	{
		next_frame_cycle(anim, &next);
	}
	render_player(mlx);
}

void	render_player(t_mlx *mlx)
{
	t_animation	*anim;
	void		*sprite;
	int			x;
	int			y;

	anim = &mlx->player.anim[mlx->player.direction];
	sprite = anim->frames[anim->current_frame];
	x = mlx->player.x * 64;
	y = mlx->player.y * 64;
	mlx_put_image_to_window(mlx->mlx_connect, mlx->mlx_window, sprite, x, y);
}
