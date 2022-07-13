#include "../inc/header.h"

int	render_frame(t_main *cs)
{
//	mlx_clear_window(cs->data.mlx, cs->data.mlx_win);
//	printf("NEXT FRAME\n");
//	printf("x: %.4f		y: %.4f\n", cs->ppos.x + cs->ppos.x_off - PLAYER_SCALE/2, cs->ppos.y + cs->ppos.y_off - PLAYER_SCALE/2);
	reset_img(cs);
	img_initializer(cs);
	draw_minimap(cs);
	draw_player_pos(cs);
	draw_floor_ceiling(cs);
	draw_rays2D(cs);
	draw_crosshair(cs);
	image_to_window(cs);
	count_fps(cs);
	move_player(cs);
//	reset_img(cs);
	return(0);
}

void	loop(t_main *cs)
{
	controls(cs);
	mlx_loop_hook(cs->data.mlx, render_frame, cs);
	mlx_loop(cs->data.mlx);
}

int main(int ac, char **av)
{
	t_main	*cs;

	if (ac != 2)
		exit(0);
	cs = pos_init();
	cs->mapdata = mapfile_reader(av[1]);
	cs->map_d = get_map_dimensions(cs->mapdata);
	cs->data = initialize_wind();
	get_assets(cs);
//	draw_minimap(cs);
	mlx_mouse_hide();
	img_initializer(cs);
//	draw_minimap(cs);
	loop(cs);
}
