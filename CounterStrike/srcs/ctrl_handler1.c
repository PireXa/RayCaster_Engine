#include "../inc/header.h"

void	reset_img(t_main *cs)
{
	ft_bzero(cs->rc.addr, WIND_H * WIND_W * (cs->rc.bi_per_pxl / 8));
	ft_bzero(cs->p.addr, PLAYER_SCALE * PLAYER_SCALE * (cs->p.bi_per_pxl / 8));
	ft_bzero(cs->map.addr, (WIND_H / 2.9) * (WIND_W / 2.9) * (cs->map.bi_per_pxl / 8));
	mlx_destroy_image(cs->data.mlx, cs->rc.img);
	mlx_destroy_image(cs->data.mlx, cs->map.img);
	mlx_destroy_image(cs->data.mlx, cs->p.img);
}

t_counters	p_position_on_map(int x, int y)
{
	t_counters	z;

	z.i = -1;
	z.e = -1;
	while((MINIMAP_X + MAP_SCALE * ++z.e) <= x);
	while((MINIMAP_Y + MAP_SCALE * ++z.i) <= y);
	z.e--;
	z.i--;
	return (z);
}

int	get_next_wall(t_main *cs, int x, int y, char d)
{
	t_counters      z;
	int		i;
	int		tx;
	int		ty;

	i = -1;
	tx = x;
	ty = y;
	if (d == 'w')
	{
		z = p_position_on_map(tx, ty);
		while (cs->mapdata[z.i][z.e] != '1')
			z = p_position_on_map(tx, --ty);
		return (y - ty - 1);
	}
	if (d == 'a')
	{
		z = p_position_on_map(tx, ty);
		while (cs->mapdata[z.i][z.e] != '1')
			z = p_position_on_map(--tx, ty);
		return (x - tx - 1);
	}
	if (d == 's')
	{
		z = p_position_on_map(tx, ty);
		while (cs->mapdata[z.i][z.e] != '1')
			z = p_position_on_map(tx, ++ty);
		return (ty - y - 1);
	}
	if (d == 'd')
	{
		z = p_position_on_map(tx, ty);
		while (cs->mapdata[z.i][z.e] != '1')
			z = p_position_on_map(++tx, ty);
		return (tx - x - 1);
	}
	return(23);
}

int	check_collision(t_main *cs, char d)
{
	t_counters	z;
	int		x;
	int		y;
	int		border_dis;
	int		flag;

	flag = -1;
	if (d == 'w')
	{
		border_dis = STEP + PLAYER_SCALE / 2;
		x = cs->ppos.x + cs->ppos.x_off - PLAYER_SCALE / 2;
		y = cs->ppos.y + cs->ppos.y_off - border_dis;
		z = p_position_on_map(x, y);
		if (cs->mapdata[z.i][z.e] == '1')
			return (get_next_wall(cs, x, cs->ppos.y + cs->ppos.y_off - PLAYER_SCALE / 2, 'w'));
		x = cs->ppos.x + cs->ppos.x_off + PLAYER_SCALE / 2;
		z = p_position_on_map(x, y);
		if (cs->mapdata[z.i][z.e] == '1')
                        return (get_next_wall(cs, x, cs->ppos.y + cs->ppos.y_off - PLAYER_SCALE / 2, 'w'));
	}
	else if (d == 'a')
        {
		border_dis = STEP + PLAYER_SCALE / 2;
		x = cs->ppos.x + cs->ppos.x_off - border_dis;
		y = cs->ppos.y + cs->ppos.y_off - PLAYER_SCALE / 2;
		z = p_position_on_map(x, y);
		if (cs->mapdata[z.i][z.e] == '1')
			return (get_next_wall(cs, cs->ppos.x + cs->ppos.x_off - PLAYER_SCALE / 2, y, 'a'));
		y = cs->ppos.y + cs->ppos.y_off + PLAYER_SCALE / 2;
		z = p_position_on_map(x, y);
		if (cs->mapdata[z.i][z.e] == '1')
			return (get_next_wall(cs, cs->ppos.x + cs->ppos.x_off - PLAYER_SCALE / 2, y, 'a'));
        }
	else if (d == 's')
        {
                border_dis = STEP + PLAYER_SCALE / 2;
                x = cs->ppos.x + cs->ppos.x_off - PLAYER_SCALE / 2;
                y = cs->ppos.y + cs->ppos.y_off + border_dis;
		z = p_position_on_map(x, y);
		if (cs->mapdata[z.i][z.e] == '1')
                        return (get_next_wall(cs, x, cs->ppos.y + cs->ppos.y_off + PLAYER_SCALE / 2, 's'));
                x = cs->ppos.x + cs->ppos.x_off + PLAYER_SCALE / 2;
                z = p_position_on_map(x, y);
		if (cs->mapdata[z.i][z.e] == '1')
                        return (get_next_wall(cs, x, cs->ppos.y + cs->ppos.y_off + PLAYER_SCALE / 2, 's'));
        }
	else if (d == 'd')
        {       
                border_dis = STEP + PLAYER_SCALE / 2;
                x = cs->ppos.x + cs->ppos.x_off + border_dis;
                y = cs->ppos.y + cs->ppos.y_off - PLAYER_SCALE / 2;
                z = p_position_on_map(x, y);
		if (cs->mapdata[z.i][z.e] == '1')
                        return (get_next_wall(cs, cs->ppos.x + cs->ppos.x_off + PLAYER_SCALE / 2, y, 'd'));
                y = cs->ppos.y + cs->ppos.y_off + PLAYER_SCALE / 2;
                z = p_position_on_map(x, y);
		if (cs->mapdata[z.i][z.e] == '1')
                       	return (get_next_wall(cs, cs->ppos.x + cs->ppos.x_off + PLAYER_SCALE / 2, y, 'd'));
        }
//	printf("e: %d\ni: %d\n\n", e, i);
	return(flag);
}

void	move_player(int key, t_main *cs)
{
//	reset_img(cs);
	int	test_dist;

	if (key == 13)
	{
		test_dist = check_collision(cs, 'w');
		if (test_dist == -1)
			cs->ppos.y_off -= STEP;
		else
			cs->ppos.y_off -= test_dist;
	}
	else if (key == 0)
	{
		test_dist = check_collision(cs, 'a');
		if (test_dist == -1)
			cs->ppos.x_off -= STEP;
		else
			cs->ppos.x_off -= test_dist;
	}
	else if (key == 1)
	{
		test_dist = check_collision(cs, 's');
		if (test_dist == -1)
			cs->ppos.y_off += STEP;
		else
			cs->ppos.y_off += test_dist;
	}
	else if (key == 2)
	{
		test_dist = check_collision(cs, 'd');
		if (test_dist == -1)
			cs->ppos.x_off += STEP;
		else
			cs->ppos.x_off += test_dist;
	}
}

void	look_left(t_main *cs)
{
	cs->ppos.pov -= 0.02;
}

void    look_right(t_main *cs)
{
	cs->ppos.pov += 0.02;
}

void	look(int key, t_main *cs)
{
//	reset_img(cs);	
	if (key == 12)
		look_left(cs);
	else if (key == 14)
		look_right(cs);
}
