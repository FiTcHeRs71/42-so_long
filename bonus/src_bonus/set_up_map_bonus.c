
#include "../include_bonus/so_long_bonus.h"

void	set_up_map(t_mlx *mlx)
{
	int		y;
	size_t	i;

	y = 0;
	i = 0;
	while (mlx->args[i])
	{
		render_line(mlx->args[i], mlx, y);
		y++;
		i++;
	}
}

void	render_line(char *line, t_mlx *mlx, int y)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		draw_with_img(mlx, line[x], x, y);
		x++;
	}
}

void	draw_with_img(t_mlx *mlx, char c, int x, int y)
{
	void	*texture;

	if (c == '1')
		texture = mlx->tex.tree;
	else if (c == '0')
		texture = mlx->tex.grass;
	else if (c == 'E')
		texture = mlx->tex.esc;
	else if (c == 'C')
		texture = mlx->tex.eat;
	else if (c == 'P')
		texture = mlx->tex.player;
	else
		texture = mlx->tex.grass;
	mlx_put_image_to_window(mlx->mlx_connect, mlx->mlx_window, texture, x * 64,
		y * 64);
}
