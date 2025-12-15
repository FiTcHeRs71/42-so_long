
#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_game		game;

	if (argc != 2)
	{
		ft_printf("%s", argv[0]); // message derreur
		return(0); // a check
	}
	ft_memset(&mlx, 0, sizeof(mlx));
	ft_memset(&game, 0, sizeof(game));
	init_data(&mlx, argv);
	handle_window(&mlx);
	load_textures(&mlx);
	init_player(&mlx);
	set_up_map(&mlx);
	mlx_loop(mlx.mlx_connect);
	return (0);
}
