#include "../include_bonus/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_mlx mlx;

	if (argc != 2)
	{
		ft_printf("Error.\n");
		ft_printf("Usage: ./so_long_bonus <valid_map.ber>\n");
		return (0);
	}
	ft_memset(&mlx, 0, sizeof(mlx));
	init_data(&mlx, argv);
	handle_window_bonus(&mlx);
	load_textures(&mlx);
	load_player_animations(&mlx);
	init_player(&mlx);
	set_up_map(&mlx);
	mlx_loop(mlx.mlx_connect);
	return (0);
}