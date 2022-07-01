#include "../inc/header.h"
  
void    put_pxl(t_wind *img, int x, int y, int color)
{
        char    *dst;

        dst = img->addr + (y * img->line_length + x * (img->bi_per_pxl / 8));
        *(unsigned int*)dst = color;
}

void	put_tile(t_wind img, int curr_x, int curr_y, int scale, int clr)
{
	int	x;
	int	y;

	x = curr_x - 1;
	y = curr_y - 1;
	while (++x < curr_x + scale)
	{
		while (++y < curr_y + scale)
			put_pxl(&img, x, y, clr);
		y = curr_y - 1;
	}
}

t_p_pos	draw_minimap(t_wind img, char **map)
{
	int	start_x;
	int	start_y;
	int	curr_x;
	int	curr_y;
	int	scale;
	int	i;
	int	e;
	t_p_pos	ppos;

	start_x = 40;
	start_y = 30;
	curr_x = start_x;
	curr_y = start_y;
	scale = 20;
	i = -1;
	e = -1;
	while (map[++i])
	{
		while (map[i][++e] != '\0')
		{
			if (map[i][e] == '0')
				put_tile(img, curr_x, curr_y, scale, 0x76f6d3);
			else if (map[i][e] == '1')
				put_tile(img, curr_x, curr_y, scale, 0x6a6a6a);
			else if (map[i][e] == 'P')
			{
				put_tile(img, curr_x, curr_y, scale, 0x76f6d3);
				ppos.x = curr_x + (scale / 2) - 2;
				ppos.y = curr_y + (scale / 2) - 2;
			}
			curr_x += scale;
		}
		e = -1;
		curr_y += scale;
		curr_x = start_x;
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	return(ppos);
}
