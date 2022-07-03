#include "../inc/header.h"

void	image_to_window(t_main *cs)
{
	mlx_put_image_to_window(cs->data.mlx, cs->data.mlx_win, cs->rc.img, 0, 0);
	mlx_put_image_to_window(cs->data.mlx, cs->data.mlx_win, cs->map.img, 0, 0);
	mlx_put_image_to_window(cs->data.mlx, cs->data.mlx_win, cs->p.img,
	cs->ppos.x + cs->ppos.x_off - PLAYER_SCALE/2,
	cs->ppos.y + cs->ppos.y_off - PLAYER_SCALE/2);
}
