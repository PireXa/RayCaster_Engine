#include "../inc/header.h"

void    draw_crosshair(t_main *cs)
{
	int	x;
	int	y;
	int	y_cap;
	int	x_cap;

	x = WIND_W / 2;
	x_cap = (WIND_W / 2) + CROSSHAIR_SIZE;
	y = (WIND_H / 2) - CROSSHAIR_SIZE - 1;
	y_cap = (WIND_H / 2) + CROSSHAIR_SIZE;
	while (++y < y_cap)
		if (!(y > ((WIND_H / 2) - CROSSHAIR_GAP) && y < ((WIND_H / 2) + CROSSHAIR_GAP)))
			put_pxl(&cs->rc, x, y, CROSSHAIR_COLOR);
	x = (WIND_W / 2) - CROSSHAIR_SIZE -1;
	y = WIND_H / 2;
	while (++x < x_cap)
		if (!(x > ((WIND_W / 2) - CROSSHAIR_GAP) && x < ((WIND_W / 2) + CROSSHAIR_GAP)))
			put_pxl(&cs->rc, x, y, CROSSHAIR_COLOR);
}
