#include "../inc/header.h"

t_wind	initialize_wind()
{
	t_wind img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIND_W, WIND_H, "Countere Seteraique");
	return(img);
}

t_main *pos_init()
{
	t_main *cs;

	cs = (t_main*)malloc(sizeof(t_main));
	cs->ppos = *(t_p_pos *)malloc(sizeof(t_p_pos));
	cs->ppos.x = 0;
	cs->ppos.y = 0;
	cs->ppos.x_off = 0;
	cs->ppos.y_off = 0;
	cs->ppos.pov = 0;
	cs->ppos.hand = 3;
	cs->fps.frame_ctr = 0;
	cs->fps.time = time(NULL);
	cs->fps.fps = 0;
	return (cs);
}

void	img_initializer(t_main *cs)
{
	cs->map.img = mlx_new_image(cs->data.mlx, WIND_W/2.9, WIND_H/2.9);
	cs->map.addr = mlx_get_data_addr(cs->map.img, &cs->map.bi_per_pxl, &cs->map.line_length, &cs->map.endian);
	cs->p.img = mlx_new_image(cs->data.mlx, PLAYER_SCALE, PLAYER_SCALE);
	cs->p.addr = mlx_get_data_addr(cs->p.img, &cs->p.bi_per_pxl, &cs->p.line_length, &cs->p.endian);
	cs->rc.img = mlx_new_image(cs->data.mlx, WIND_W, WIND_H);
	cs->rc.addr = mlx_get_data_addr(cs->rc.img, &cs->rc.bi_per_pxl, &cs->rc.line_length, &cs->rc.endian);
}
