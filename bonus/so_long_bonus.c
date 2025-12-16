
#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_game		game;

	if (argc != 2)
	{
		ft_printf("ERROR\n");
		ft_printf("Usage ./so_long <valid map> ");
		return (0);
	}
	ft_memset(&mlx, 0, sizeof(mlx));
	ft_memset(&game, 0, sizeof(game));
}