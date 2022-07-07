#include "../inc/header.h"

void	image_to_window(t_main *cs)
{
	int	x;
	int	y;

	x = cs->ppos.x + cs->ppos.x_off - PLAYER_SCALE/2;
	y = cs->ppos.y + cs->ppos.y_off - PLAYER_SCALE/2;
	mlx_put_image_to_window(cs->data.mlx, cs->data.mlx_win, cs->rc.img, 0, 0);
	mlx_put_image_to_window(cs->data.mlx, cs->data.mlx_win, cs->map.img, 0, 0);
	if (x > 0 && x < WIND_W/2 && y > 0 && y < WIND_H/2)
	{
		mlx_put_image_to_window(cs->data.mlx, cs->data.mlx_win, cs->p.img, x, y);
	}
	if (cs->ppos.hand == 3)
		mlx_put_image_to_window(cs->data.mlx, cs->data.mlx_win, cs->ass.m9.img, WIND_W * 0.1, (WIND_H/2) * 1.19);
	else if (cs->ppos.hand == 2)
		mlx_put_image_to_window(cs->data.mlx, cs->data.mlx_win, cs->ass.glock.img, WIND_W/2, (WIND_H/2) * 1.19);
	else if (cs->ppos.hand == 1)
		mlx_put_image_to_window(cs->data.mlx, cs->data.mlx_win, cs->ass.ak.img, WIND_W/2, (WIND_H/2) * 1.19);
}
