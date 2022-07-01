#include "../inc/header.h"

void	draw_player_pos(t_main *cs)
{
	int	i;
	int	e;

	i = -1;
	e = -1;
	while (++i < 5)
	{
		while (++e < 5)
		{
			put_pxl(&cs->img, cs->ppos.x + cs->ppos.x_off + i, cs->ppos.y + cs->ppos.x_off + e, 0x00009f);
		}
		e = -1;
	}
	mlx_put_image_to_window(cs->img.mlx, cs->img.mlx_win, cs->img.img, 0, 0);
}
