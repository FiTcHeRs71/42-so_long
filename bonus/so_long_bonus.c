
#include "../include/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;

	if (argc != 2)
	{
		ft_printf("Error.\n");
		ft_printf("Usage ./so_long_bonus <valid map> ");
		return (0);
	}
	ft_memset(&mlx, 0, sizeof(mlx));
	init_data(&mlx, argv);
	handle_window(&mlx);
	load_textures(&mlx);
	load_player_animations(&mlx);
}
