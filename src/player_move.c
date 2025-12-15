
#include "../include/so_long.h"

void	player_move(t_mlx *mlx, int move)
{
	mlx->game.count += 1;
	if(move == UP)
	{
		ft_printf("UP.\n");
		move_up(mlx);
	}
	else if (move == DOWN)
	{
		ft_printf("Down.\n");
	}
	else if (move == RIGHT)
	{
		ft_printf("Right.\n");
	}
	else if (move == LEFT)
	{
		ft_printf("Left.\n");
	}
}
void	move_up(t_mlx *mlx)
{

}