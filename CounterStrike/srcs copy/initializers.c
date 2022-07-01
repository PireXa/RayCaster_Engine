#include "../inc/header.h"

t_wind	initialize_wind()
{
	t_wind img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIND_W, WIND_H, "Countere Seteraique");
	img.img = mlx_new_image(img.mlx, WIND_W, WIND_H);
	img.addr = mlx_get_data_addr(img.img, &img.bi_per_pxl, &img.line_length, &img.endian);
	return(img);
}

t_main *pos_init()
{
	t_main *cs;

	cs = (t_main*)malloc(sizeof(t_main));
	cs->ppos.x = 0;
	cs->ppos.y = 0;
	cs->ppos.x_off = 0;
	cs->ppos.y_off = 0;
	return (cs);
}
