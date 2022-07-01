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
			printf("x: %d\ny: %d\n", x, y);
			z = p_position_on_map(x1 + ++x, y);
			while(z.e == p_position_on_map(x1 + ++x, y).e);
			return(x);
		}
		else
		{
			x = x1;
			y = PLAYER_SCALE / 2;
			z = p_position_on_map(x, y1 + ++y);
			while(z.i == p_position_on_map(x, y1 + ++y).i);
			return(y);
		}
	}
	else
	{
		if (d[1] == 'x')
		{
			x = -(PLAYER_SCALE / 2);
			y = y1;
			z = p_position_on_map(x1 + --x, y);
			while(z.e == p_position_on_map(x1 + --x, y).e);
			return(x);
		}
		else
		{
			x = x1;
			y = -(PLAYER_SCALE / 2);
			z = p_position_on_map(x, y1 + --y);
			while(z.i == p_position_on_map(x, y1 + --y).i);
			return(y);
		}
	}
}

void	neg_inf_slope(int x, int y1, int y2, t_img img)
{
	int	y;

	y = y1;
	while (y != y2)
		put_pxl(&img, x, --y, 0x0000ff);
}

void    pos_inf_slope(int x, int y1, int y2, t_img img)
{
	int	y;

	y = y1;
	while ((y != y2) && (y + 3) < WIND_H/2.9)
		put_pxl(&img, x, ++y, 0x0000ff);
}

void	neg_slope(float m_slope, float x1, int y1, int x2, int y2, t_img img)
{
	float	t_slope;
	int	x;
	int	y;

	x = x1;
	y = y1;
	put_pxl(&img, ++x, y, 0x0000ff);
	while ((x != x2 || y != y2) && (x + 3) < WIND_W/2.9)
	{
		t_slope = slope(x1, y1, x, y);
		if (t_slope >= m_slope)
		{
			put_pxl(&img, x, --y, 0x0000ff);
		}
		else
		{
			put_pxl(&img, ++x, y, 0x0000ff);
		}
	}
}

void    pos_slope(float m_slope, float x1, int y1, int x2, int y2, t_img img)
{
	float	t_slope;
	int	x;
	int	y;
	int	nxt_tx;
	int	nxt_ty;

	x = x1;
	y = y1;
	nxt_tx = get_next_tile(x1, y1, "+x");
	nxt_ty = get_next_tile(x1, y1, "+y");
	printf("nxt_tx: %d\nnxt_ty: %d\n\n", nxt_tx, nxt_ty);
	put_pxl(&img, ++x, y, 0x0000ff);
	while ((x != x2 || y != y2) && (x + 3) < WIND_W/2.9 && (y + 3) < WIND_H/2.9)
	{
		t_slope = slope(x1, y1, x, y);
		if (t_slope >= m_slope)
			put_pxl(&img, ++x, y, 0x0000ff);
		else
			put_pxl(&img, x, ++y, 0x0000ff);
	}
}

void	ray_drawer(float x1, int y1, int x2, int y2, t_img img)
{
	float	m_slope;
	float	tmp;

	
//	printf("x1: %.2f\ny1: %d\nx2: %d\ny2: %d\n", x1, y1, x2, y2);
	if (x2 < x1)
	{
		tmp = x1;
		x1 = x2;
		x2 = tmp;
		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}
	m_slope = slope(x1, y1, x2, y2);
//	printf("slope: %.4f\n", m_slope);
	if (m_slope < -10000)
		neg_inf_slope(x1, y1, y2, img);
	else if (m_slope > 10000)
		pos_inf_slope(x1, y1, y2, img);
	else if (m_slope < 0.0000)
		neg_slope(m_slope, x1, y1, x2, y2, img);
	else
		pos_slope(m_slope, x1, y1, x2, y2, img);
}
