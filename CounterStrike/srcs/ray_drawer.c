#include "../inc/header.h"

float	slope(float x1, int y1, int x2, int y2)
{
	float	ret;

	ret = (y2 - y1) / (x2 - x1);
	return (ret);
}

int	get_next_tile(int x1, int y1, char *d)
{
	int		x;
	int		y;
	t_counters	z;

	if (d[0] == '+')
	{
		if (d[1] == 'x')
		{
			x = PLAYER_SCALE / 2;
			y = y1;
	//		printf("x: %d\ny: %d\n", x, y);
			z = p_position_on_map(x1 + x++, y);
			while(z.e == p_position_on_map(x1 + x++, y).e);
			return(x);
		}
		else
		{
			x = x1;
			y = PLAYER_SCALE / 2;
			z = p_position_on_map(x, y1 + y++);
			while(z.i == p_position_on_map(x, y1 + y++).i);
			return(y);
		}
	}
	else
	{
		if (d[1] == 'x')
		{
			x = -(PLAYER_SCALE / 2);
			y = y1;
			z = p_position_on_map(x1 + x--, y);
			while(z.e == p_position_on_map(x1 + x--, y).e);
			return(x);
		}
		else
		{
			x = x1;
			y = -(PLAYER_SCALE / 2);
			z = p_position_on_map(x, y1 + y--);
			while(z.i == p_position_on_map(x, y1 + y--).i);
			return(y);
		}
	}
}

void	neg_inf_slope(float pov_ang, float ray_ang, int x, int y1, int y2, t_img img, t_main *cs)
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
				render_3d(cs, pov_ang, ray_ang, x, y1, x, y);
				return;
			}
			else
				nxt_ty -= MAP_SCALE;
		}
		put_pxl(&img, x, --y, RAY_COLOR);
	}
}

void    pos_inf_slope(float pov_ang, float ray_ang, int x, int y1, int y2, t_img img, t_main *cs)
{
	int		y;
	int             nxt_ty;
	t_counters      z;

	y = y1;
	nxt_ty = get_next_tile(x, y1, "+y");
	while ((y != y2) && (y + 3) < WIND_H/2.9)
	{
		if (y - y1 == nxt_ty)
		{
			z = p_position_on_map(x, y);
			if (cs->mapdata[z.i][z.e] == '1')
			{
				render_3d(cs, pov_ang, ray_ang, x, y1, x, y);
				return;
			}
			else
				nxt_ty += MAP_SCALE;
		}
		put_pxl(&img, x, ++y, RAY_COLOR);
	}
}

void	neg_slope(float pov_ang, float ray_ang, float m_slope, float x1, int y1, int x2, int y2, t_img img, char d, t_main *cs)
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
		while ((x != x2 || y != y2) && (x + 3) < WIND_W/2.9 && y > 0)
		{
			if (x - x1 == nxt_tx)
			{
				z = p_position_on_map(x, y);
				if (cs->mapdata[z.i][z.e] == '1')
				{
					render_3d(cs, pov_ang, ray_ang, x1, y1, x, y);
					return;
				}
				else
					nxt_tx += MAP_SCALE;
			}
			if (y - y1 == nxt_ty)
			{
				z = p_position_on_map(x, y);
				if (cs->mapdata[z.i][z.e] == '1')
				{
					render_3d(cs, pov_ang, ray_ang, x1, y1, x, y);
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
				put_pxl(&img, ++x, y, RAY_COLOR);
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
			if (x - x1 == nxt_tx)
			{
				z = p_position_on_map(x, y);
				if (cs->mapdata[z.i][z.e] == '1')
				{
					render_3d(cs, pov_ang, ray_ang, x1, y1, x, y);
					return;
				}
				else
					nxt_tx -= MAP_SCALE;
			}
			if (y - y1 == nxt_ty)
			{
				z = p_position_on_map(x, y);
				if (cs->mapdata[z.i][z.e] == '1')
				{
					render_3d(cs, pov_ang, ray_ang, x1, y1, x, y);
					return;
				}
				else
					nxt_ty += MAP_SCALE;
			}
			t_slope = slope(x1, y1, x, y);
			if (t_slope >= m_slope)
				put_pxl(&img, x, ++y, RAY_COLOR);
			else
				put_pxl(&img, --x, y, RAY_COLOR);
		}
	}
}

void    pos_slope(float pov_ang, float ray_ang, float m_slope, float x1, int y1, int x2, int y2, t_img img, char d, t_main *cs)
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
		while ((x != x2 || y != y2) && (x + 3) < WIND_W/2.9 && (y + 3) < WIND_H/2.9)
		{
			if (x - x1 == nxt_tx)
			{
				z = p_position_on_map(x, y);
				if (cs->mapdata[z.i][z.e] == '1')
				{
					render_3d(cs, pov_ang, ray_ang, x1, y1, x, y);
					return;
				}
				else
					nxt_tx += MAP_SCALE;
			}
			if (y - y1 == nxt_ty)
			{
				z = p_position_on_map(x, y);
				if (cs->mapdata[z.i][z.e] == '1')
				{
					render_3d(cs, pov_ang, ray_ang, x1, y1, x, y);
					return;
				}
				else
					nxt_ty += MAP_SCALE;
			}
			t_slope = slope(x1, y1, x, y);
			if (t_slope >= m_slope)
				put_pxl(&img, ++x, y, RAY_COLOR);
			else
				put_pxl(&img, x, ++y, RAY_COLOR);
		}
	}
	else
	{
		nxt_tx = get_next_tile(x1, y1, "-x");
		nxt_ty = get_next_tile(x1, y1, "-y");
		put_pxl(&img, --x, y, RAY_COLOR);
		while ((x != x2 || y != y2) && x > 0)
		{
			if (x - x1 == nxt_tx)
			{
				z = p_position_on_map(x, y);
				if (cs->mapdata[z.i][z.e] == '1')
				{
					render_3d(cs, pov_ang, ray_ang, x1, y1, x, y);
					return;
				}
				else
					nxt_tx -= MAP_SCALE;
			}
			if (y - y1 == nxt_ty)
			{
				z = p_position_on_map(x, y);
				if (cs->mapdata[z.i][z.e] == '1')
				{
					render_3d(cs, pov_ang, ray_ang, x1, y1, x, y);
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

void	ray_drawer(float pov_ang, float ray_ang, float x1, int y1, int x2, int y2, t_img img, t_main *cs)
{
	float	m_slope;

	m_slope = slope(x1, y1, x2, y2);
//	printf("slope: %.4f\n", m_slope);
	if (m_slope < -10000)
		neg_inf_slope(pov_ang, ray_ang, x1, y1, y2, img, cs);
	else if (m_slope > 10000)
		pos_inf_slope(pov_ang, ray_ang, x1, y1, y2, img, cs);
	else if (m_slope < 0.0000)
	{
		if (x1 < x2)
			neg_slope(pov_ang, ray_ang, m_slope, x1, y1, x2, y2, img, '1', cs);
		else
			neg_slope(pov_ang, ray_ang, m_slope, x1, y1, x2, y2, img, '2', cs);
	}
	else
	{
		if (x1 < x2)
			pos_slope(pov_ang, ray_ang, m_slope, x1, y1, x2, y2, img, '1', cs);
		else
			pos_slope(pov_ang, ray_ang, m_slope, x1, y1, x2, y2, img, '2', cs);
	}
}
