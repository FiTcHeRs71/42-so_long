
#include "../include_bonus/so_long_bonus.h"

void	init_data(t_mlx *mlx, char **argv)
{
	int	fd;

	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		ft_error("map has to be .ber\n", mlx);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_error("Unable to open map file\n", mlx);
	}
	mlx->args = fill_args(fd);
	close(fd);
	if (!mlx->args || !mlx->args[0])
	{
		ft_error("The map must be not empty.", mlx);
	}
	check_map(mlx, mlx->args);
	mlx->window.size_x = (ft_strlen(mlx->args[0])) * 64;
	mlx->window.size_y = count_line(mlx->args) * 64;
	check_map_border(mlx);
	check_map_border_2(mlx);
	mlx->game.state = STATE_MENU;
}

int	count_line(char **args)
{
	size_t	i;
	int		size_y;

	i = 0;
	size_y = 0;
	while (args[i])
	{
		size_y += 1;
		i++;
	}
	return (size_y);
}

char	**fill_args(int fd)
{
	char	*line;
	char	*temp;
	char	*old_temp;
	char	**args;

	temp = ft_strdup("");
	if (!temp)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		old_temp = temp;
		temp = ft_strjoin(temp, line);
		free(old_temp);
		free(line);
		if (!temp)
			return (NULL);
		line = get_next_line(fd);
	}
	args = ft_split(temp, '\n');
	free(temp);
	return (args);
}

void	check_map_border(t_mlx *mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (mlx->args[j])
		j++;
	while (mlx->args[0][i])
	{
		if (mlx->args[0][i] != '1')
		{
			ft_error("The map must be surrounded by a border.\n", mlx);
		}
		i++;
	}
	i = 0;
	while (mlx->args[j - 1][i])
	{
		if (mlx->args[j - 1][i] != '1')
		{
			ft_error("The map must be surrounded by a border.\n", mlx);
		}
		i++;
	}
}

void	check_map_border_2(t_mlx *mlx)
{
	size_t	i;
	size_t	len;

	i = 0;
	
	while (mlx->args[i])
	{
		len = ft_strlen(mlx->args[i]);
		if ((len > 0) && (mlx->args[i][0] != '1' || mlx->args[i][len - 1] != '1'))
		{
			ft_error("The map must be surrounded by a border.\n", mlx);
		}
		i++;
	}
}
