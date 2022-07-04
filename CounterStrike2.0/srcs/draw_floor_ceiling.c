#include "../inc/header.h"

void    draw_floor_ceiling(t_main *cs)
{
	int	x;
	int	y;
	int	y_cap;

	x = -1;
	y = -1;
	y_cap = WIND_H / 2;
	while (++x < WIND_W)
	{
		while (++y < y_cap)
			put_pxl(&cs->rc, x , y, CEILING_COLOR);
		y = -1;
	}
	x = -1;
	y = y_cap - 1;
	while (++x < WIND_W)
	{
		while (++y < WIND_H)
			put_pxl(&cs->rc, x , y, FLOOR_COLOR);
		y = y_cap - 1;
	}
}
