#include "../inc/header.h"
  
void    put_pxl(t_img *img, int x, int y, int color)
{
        char    *dst;

	if (x >= 0 && x < WIND_W && y >= 0 && y < WIND_H)
	{
		dst = img->addr + (y * img->line_length + x * (img->bi_per_pxl / 8));
		*(unsigned int*)dst = color;
	}
}

void	put_tile(t_img img, int curr_x, int curr_y, int clr)
{
	int	x;
	int	y;

	x = curr_x - 1;
	y = curr_y - 1;
	while (++x < curr_x + MAP_SCALE - 1 && x > 0 && x < WIND_W/2.9)
	{
		while (++y < curr_y + MAP_SCALE - 1 && y > 0 && y < WIND_H/2.9)
		{
			if (x < WIND_W/2.9 && y < WIND_H/2.9)
				put_pxl(&img, x, y, clr);
		}
		y = curr_y - 1;
	}
}

void	draw_minimap(t_main *cs)
{
	float	start_x;
	float	start_y;
	float	curr_x;
	float	curr_y;
	int	i;
	int	e;

	start_x = MINIMAP_X;
	start_y = MINIMAP_Y ;
	curr_x = start_x;
	curr_y = start_y;
	i = -1;
	e = -1;
	while (cs->mapdata[++i])
	{
		while (cs->mapdata[i][++e] != '\0')
		{
			if (cs->mapdata[i][e] == '0')
				put_tile(cs->map, curr_x, curr_y, MM_FLOOR_COLOR);
			else if (cs->mapdata[i][e] == '1')
				put_tile(cs->map, curr_x, curr_y, MM_WALL_COLOR);
			else if (cs->mapdata[i][e] == 'P')
			{
				put_tile(cs->map, curr_x, curr_y, MM_FLOOR_COLOR);
				cs->ppos.x = curr_x + (MAP_SCALE / 2);
				cs->ppos.y = curr_y + (MAP_SCALE / 2);
			}
			curr_x += MAP_SCALE;
		}
		e = -1;
		curr_y += MAP_SCALE;
		curr_x = start_x;
	}
}
