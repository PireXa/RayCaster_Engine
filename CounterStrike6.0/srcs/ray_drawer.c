#include "../inc/header.h"

float	slope(float x1, float y1, float x2, float y2)
{
	float	ret;

	ret = (y2 - y1) / (x2 - x1);
	return (ret);
}

float	get_next_tile(float x1, float y1, char *d)
{
	float		x;
	float		y;
	t_counters	z;

	if (d[0] == '+')
	{
		if (d[1] == 'x')
		{
			x = 0;//PLAYER_SCALE / 2;
			y = y1;
	//		printf("x: %d\ny: %d\n", x, y);
			z = p_position_on_map(x1 + x, y);
			x += 1.0f;
			while(z.e == p_position_on_map(x1 + x, y).e)
				x += 1.0f;
			return(x);
		}
		else
		{
			x = x1;
			y = 0;//PLAYER_SCALE / 2;
			z = p_position_on_map(x, y1 + y);
			y += 1.0f;
			while(z.i == p_position_on_map(x, y1 + y).i)
				y += 1.0f;
			return(y);
		}
	}
	else
	{
		if (d[1] == 'x')
		{
			x = 0;//-(PLAYER_SCALE / 2);
			y = y1;
			z = p_position_on_map(x1 + x, y);
			x -= 1.0f;
			while(z.e == p_position_on_map(x1 + x, y).e)
				x -= 1.0f;
			return(x);
		}
		else
		{
			x = x1;
			y = 0;//-(PLAYER_SCALE / 2);
			z = p_position_on_map(x, y1 + y);
			y -= 1.0f;
			while(z.i == p_position_on_map(x, y1 + y).i)
				y -= 1.0f;
			return(y);
		}
	}
}
/*
void	neg_inf_slope(int x, int y1, int y2, t_img img, t_main *cs)
{
	int		y;
	int		nxt_ty;
	t_counters	z;

	y = y1;
	nxt_ty = get_next_tile(x, y1, "-y");
	while (y != y2 && y > 0)
	{
		if (y - y1 == nxt_ty)
		{
			z = p_position_on_map(x, y);
			if (cs->mapdata[z.i][z.e] == '1')
			{
				render_3d(cs, x, y1, x, y, 1);
				return;
			}
			else
				nxt_ty -= MAP_SCALE;
		}
		put_pxl(&img, x, --y, RAY_COLOR);
	}
}

void    pos_inf_slope(int x, int y1, int y2, t_img img, t_main *cs)
{
	int		y;
	int             nxt_ty;
	t_counters      z;

	y = y1;
	nxt_ty = get_next_tile(x, y1, "+y");
	while (y != y2)
	{
		if (y - y1 == nxt_ty)
		{
			z = p_position_on_map(x, y);
			if (cs->mapdata[z.i][z.e] == '1')
			{
				render_3d(cs, x, y1, x, y, 3);
				return;
			}
			else
				nxt_ty += MAP_SCALE;
		}
		y++;
		if (y < WIND_H/2.9)
			put_pxl(&img, x, y, RAY_COLOR);
	}
}
*/
void	neg_slope(float m_slope, float x1, float y1, float x2, float y2, t_img img, char d, t_main *cs)
{
	float		t_slope;
	int		x;
	int		y;
	int		nxt_tx;
	int		nxt_ty;
	t_counters	z;

	x = x1;
	y = y1;
	if (d == '1')
	{
		nxt_tx = get_next_tile(x1, y1, "+x");
		nxt_ty = get_next_tile(x1, y1, "-y");
		put_pxl(&img, ++x, y, RAY_COLOR);
		while (x != x2 || y != y2)
		{
			if (x - x1 + 1>= nxt_tx)
			{
				z = p_position_on_map(x, y);
				if (z.i < 0 || z.e > cs->map_d.x)
					return;
				if (cs->mapdata[z.i][z.e] == '1' && cs->mapdata[z.i][z.e - 1] != '1')
				{
					render_3d(cs, x1, y1, x, y, 2);
					return;
				}
				if (cs->mapdata[z.i][z.e] == '1' && cs->mapdata[z.i + 1][z.e] == '1')
				{
					render_3d(cs, x1, y1, x, y, 2);
					return;
				}
				else
					nxt_tx += MAP_SCALE;
			}
			if (y - y1 <= nxt_ty)
			{
				z = p_position_on_map(x, y);
				if (z.i < 0 || z.e > cs->map_d.x)
					return;
				if (cs->mapdata[z.i][z.e] == '1' && cs->mapdata[z.i + 1][z.e] != '1')
				{
					render_3d(cs, x1, y1, x, y, 1);
					return;
				}
				else
					nxt_ty -= MAP_SCALE;
			}
			t_slope = slope(x1, y1, x, y);
			if (t_slope >= m_slope)
			{
				put_pxl(&img, x, --y, RAY_COLOR);
			}
			else
			{
				x++;
				if (x < WIND_W/2.9)
					put_pxl(&img, x, y, RAY_COLOR);
			}
		}
	}
	else
	{
		nxt_tx = get_next_tile(x1, y1, "-x");
		nxt_ty = get_next_tile(x1, y1, "+y");
		put_pxl(&img, --x, y, RAY_COLOR);
		while ((x != x2 || y != y2) && x > 0 && (y + 3) < WIND_H/2.9)
		{
			if (x - x1 <= nxt_tx)
			{
				z = p_position_on_map(x, y);
				if (z.i > cs->map_d.y || z.e < 0)
					return;
				if (cs->mapdata[z.i][z.e] == '1' && cs->mapdata[z.i][z.e + 1] != '1')
				{
					render_3d(cs, x1, y1, x, y, 4);
					return;
				}
				if (cs->mapdata[z.i][z.e] == '1' && cs->mapdata[z.i - 1][z.e] == '1')
				{
					render_3d(cs, x1, y1, x, y, 4);
					return;
				}
				else
					nxt_tx -= MAP_SCALE;
			}
			if (y - y1 + 1>= nxt_ty)
			{
				z = p_position_on_map(x, y);
				if (z.i > cs->map_d.y || z.e < 0)
					return;
				if (cs->mapdata[z.i][z.e] == '1' && cs->mapdata[z.i - 1][z.e] != '1')
				{
					render_3d(cs, x1, y1, x, y, 3);
					return;
				}
				else
					nxt_ty += MAP_SCALE;
			}
			t_slope = slope(x1, y1, x, y);
			if (t_slope >= m_slope)
			{
				y++;
				if (y < WIND_H/2.9)
					put_pxl(&img, x, y, RAY_COLOR);
			}
			else
				put_pxl(&img, --x, y, RAY_COLOR);
		}
	}
}

void    pos_slope(float m_slope, float x1, float y1, float x2, float y2, t_img img, char d, t_main *cs)
{
	float		t_slope;
	int		x;
	int		y;
	int		nxt_tx;
	int		nxt_ty;
	t_counters	z;

	x = x1;
	y = y1;
	if (d == '1')
	{
		nxt_tx = get_next_tile(x1, y1, "+x");
		nxt_ty = get_next_tile(x1, y1, "+y");
		put_pxl(&img, ++x, y, RAY_COLOR);
		while (x != x2 || y != y2)
		{
			if (x - x1 + 1 >= nxt_tx)
			{
				z = p_position_on_map(x, y);
				if (z.i > cs->map_d.y || z.e > cs->map_d.x)
					return;
				if (cs->mapdata[z.i][z.e] == '1' && cs->mapdata[z.i][z.e - 1] != '1')
				{
					render_3d(cs, x1, y1, x, y, 2);
					return;
				}
				if (cs->mapdata[z.i][z.e] == '1' && cs->mapdata[z.i - 1][z.e] == '1')
				{
					render_3d(cs, x1, y1, x, y, 2);
					return;
				}
				else
					nxt_tx += MAP_SCALE;
			}
			if (y - y1 + 1 >= nxt_ty)
			{
				z = p_position_on_map(x, y);
				if (z.i > cs->map_d.y || z.e > cs->map_d.x)
					return;
				if (cs->mapdata[z.i][z.e] == '1' && cs->mapdata[z.i - 1][z.e] != '1')
				{
					render_3d(cs, x1, y1, x, y, 3);
					return;
				}
				else
					nxt_ty += MAP_SCALE;
			}
			t_slope = slope(x1, y1, x, y);
			if (t_slope >= m_slope)
			{
				x++;
				if (x < WIND_W/2.9)
					put_pxl(&img, x, y, RAY_COLOR);
			}
			else
			{
				y++;
				if (y < WIND_H/2.9)
					put_pxl(&img, x, y, RAY_COLOR);
			}
		}
	}
	else
	{
		nxt_tx = get_next_tile(x1, y1, "-x");
		nxt_ty = get_next_tile(x1, y1, "-y");
		put_pxl(&img, --x, y, RAY_COLOR);
		while (x != x2 || y != y2)
		{
			if (x - x1 <= nxt_tx)
			{
				z = p_position_on_map(x, y);
				if (z.i < 0 || z.e < 0)
					return;
				if (cs->mapdata[z.i][z.e] == '1' && cs->mapdata[z.i][z.e + 1] != '1')
				{
					render_3d(cs, x1, y1, x, y, 4);
					return;
				}
				if (cs->mapdata[z.i][z.e] == '1' && cs->mapdata[z.i + 1][z.e] == '1')
				{
					render_3d(cs, x1, y1, x, y, 4);
					return;
				}
				else
					nxt_tx -= MAP_SCALE;
			}
			if (y - y1 <= nxt_ty)
			{
				z = p_position_on_map(x, y);
				if (z.i < 0 || z.e < 0)
					return;
				if (cs->mapdata[z.i][z.e] == '1' && cs->mapdata[z.i + 1][z.e] != '1')
				{
					render_3d(cs, x1, y1, x, y, 1);
					return;
				}
				else
					nxt_ty -= MAP_SCALE;
			}
			t_slope = slope(x1, y1, x, y);
			if (t_slope >= m_slope)
				put_pxl(&img, --x, y, RAY_COLOR);
			else
				put_pxl(&img, x, --y, RAY_COLOR);
		}
	}
}

void	ray_drawer(float x1, float y1, float x2, float y2, t_img img, t_main *cs)
{
	float	m_slope;

	m_slope = slope(x1, y1, x2, y2);
/*	printf("new ray\n");
	printf("slope: %.4f\n", m_slope);
	printf("x_dif: %.3f\n", x2 - x1);
	if ((m_slope < -10000 && x2 - x1 == 0) || (m_slope > 10000 && x2 - x1 < 0))
	{
		printf("oi\n");
		neg_inf_slope(x1, y1, y2, img, cs);
	}
	else if ((m_slope < -10000 && x2 - x1 < 0) || (m_slope > 10000 && x2 - x1 > 0))
	{
		printf("fds\n");
		pos_inf_slope(x1, y1, y2, img, cs);
	}
*/	if (m_slope < 0.0000f)
	{
		if (x1 <= x2)
		{
			neg_slope(m_slope, x1, y1, x2, y2, img, '1', cs);
		}
		else
		{
			neg_slope(m_slope, x1, y1, x2, y2, img, '2', cs);
		}
	}
	else
	{
		if (x1 <= x2)
			pos_slope(m_slope, x1, y1, x2, y2, img, '1', cs);
		else
			pos_slope(m_slope, x1, y1, x2, y2, img, '2', cs);
	}
}
