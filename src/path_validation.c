
#include "../include/so_long.h"

void		valide_path(t_mlx *mlx)
{
	char	**map_copy;
	t_flood	flood;
	int		player_x;
	int		player_y;

	ft_memset(&flood, 0, sizeof(t_flood));
	if (!find_player_position(mlx->args, &player_x, &player_y))
	{
		ft_error("Unable to find player.\n", mlx);
	}
	map_copy = copy_map(mlx->args, mlx);
	flood_fill(map_copy, player_x, player_y, &flood);
	ft_free_2d_array(map_copy, count_line(map_copy));
	if (flood.collectibles_found != mlx->flag_c)
	{
		ft_error("Unable to reach all food.\n", mlx);
	}
	if (!flood.exit_found)
	{
		ft_error("Unable to reach exit.\n", mlx);
	}
}

void	flood_fill(char **map_copy, int x, int y, t_flood *flood)
{
	if (x < 0 || y < 0 || !map_copy[y] || !map_copy[y][x])
	{
		return; //ft_error ?
	}
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
	{
		return ;
	}
	if (map_copy[y][x] == 'C')
	{
		flood->collectibles_found += 1;
	}
	if (map_copy[y][x] == 'E')
	{
		flood->exit_found = 1;
	}
	map_copy[y][x] = 'V';
	flood_fill(map_copy, x, y - 1, flood); // Haut
	flood_fill(map_copy, x, y + 1, flood); // Bas
	flood_fill(map_copy, x - 1, y, flood); // Gauche
	flood_fill(map_copy, x + 1, y, flood); // Droite
}

char	**copy_map(char **original, t_mlx *mlx)
{
	char	**copy;
	int		i;

	i = 0;
	while (original[i])
	{
		i++;
	}
	copy = ft_calloc(i + 1, sizeof(char *));
	if (!copy)
	{
		ft_error("Unable to alocate memory.\n", mlx);
	}
	i = 0;
	while (original[i])
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			ft_free_2d_array(copy, i);
			ft_error("Unable to alocate memory.\n", mlx);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	find_player_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return(1);
			}
			j++;
		}
		i++;
	}
	return(0);
}

