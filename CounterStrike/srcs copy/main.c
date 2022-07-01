#include "../inc/header.h"

void	loop(t_main *cs, char **map)
{
	cs->ppos = draw_minimap(cs->img, map);
	draw_player_pos(cs);
//	mlx_put_image_to_window(cs->img.mlx, cs->img.mlx_win, cs->img.img, 0, 0);
	controls(cs);
	mlx_loop(cs->img.mlx);
}

int main(int ac, char **av)
{
	t_main	*cs;
	char	**map;

	if (ac != 2)
		exit(0);
	cs = pos_init();
	cs->img = initialize_wind();
	map = mapfile_reader(av[1]);
	loop(cs, map);
}
