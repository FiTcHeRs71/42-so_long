
#ifndef SO_LONG_STRUCT_BONUS_H
# define SO_LONG_STRUCT_BONUS_H

# include "so_long_struct.h"

typedef struct s_animation
{
	void	**frames;
	int		frame_count;
	int		current_frame;
	int		frame_delay;
	int		tick_counter;
}	t_animation;

typedef struct s_player
{
	int	x;
	int	y;
	t_animation		anim[4];
	t_move		direction;
	int	is_moving;

}	t_player;



#endif