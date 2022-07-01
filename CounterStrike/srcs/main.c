#include "../inc/header.h"

int	render_frame(t_main *cs)
{
	draw_minimap(cs);
	draw_player_pos(cs);
	draw_rays2D(cs);
	image_to_window(cs);
	controls(cs);
	return(0);
}

void	loop(t_main *cs)
{
	mlx_loop_hook(cs->data.mlx, render_frame, cs);
	mlx_loop(cs->data.mlx);
}

int main(int ac, char **av)
{
	t_main	*cs;

	if (ac != 2)
		exit(0);
	cs = pos_init();
	cs->data = initialize_wind();
	img_initializer(cs);
	cs->mapdata = mapfile_reader(av[1]);
//	draw_minimap(cs);
	loop(cs);
}
