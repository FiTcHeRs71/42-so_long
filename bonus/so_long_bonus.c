
#include "../include/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_game		game;
	t_animation	anim;
	t_player	player;
	if (argc != 2)
	{
		ft_printf("ERROR\n");
		ft_printf("Usage ./so_long_bonus <valid map> ");
		return (0);
	}
	ft_memset(&mlx, 0, sizeof(mlx));
	ft_memset(&game, 0, sizeof(game));
	ft_memset(&anim, 0, sizeof(anim));
	ft_memset(&player, 0, sizeof(player));
	init_data(&mlx, argv);
	handle_window(&mlx);
	load_textures(&mlx);
	load_player_animations
}
