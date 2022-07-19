#include "../inc/header.h"

void	reset_img(t_main *cs)
{
//	ft_bzero(cs->rc.addr, WIND_H * WIND_W * (cs->rc.bi_per_pxl / 8));
//	ft_bzero(cs->p.addr, PLAYER_SCALE * PLAYER_SCALE * (cs->p.bi_per_pxl / 8));
//	ft_bzero(cs->map.addr, (WIND_H / 2.9) * (WIND_W / 2.9) * (cs->map.bi_per_pxl / 8));
	mlx_destroy_image(cs->data.mlx, cs->rc.img);
	mlx_destroy_image(cs->data.mlx, cs->map.img);
	mlx_destroy_image(cs->data.mlx, cs->p.img);
}

t_counters	p_position_on_map(float x, float y)
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
/*
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
*/
int	check_wall(t_main *cs, float x, float y)
{
	t_counters	z;
	int		sig_x;
	int		sig_y;
	if (x < 0)
		sig_x = -1;
	else
		sig_x = 1;
	if (y < 0)
		sig_y = -1;
	else
		sig_y = 1;
	z = p_position_on_map(cs->ppos.x + cs->ppos.x_off + x + (PLAYER_SCALE/2) * sig_x, cs->ppos.y + cs->ppos.y_off + y + (PLAYER_SCALE/2) * sig_y);
	if (cs->mapdata[z.i][z.e] == '1')
	{
		return(1);
	}
	return (0);
}

void	active_mov(int key, t_main *cs)
{
	if (key == 13)
		cs->cmds.n = 1;
	else if (key == 0)
		cs->cmds.w = 1;
	else if (key == 1)
		cs->cmds.s = 1;
	else
		cs->cmds.e = 1;
}

void    deactive_mov(int key, t_main *cs)
{
	if (key == 13)
		cs->cmds.n = 0;
	else if (key == 0)
		cs->cmds.w = 0;
	else if (key == 1)
		cs->cmds.s = 0;
	else
		cs->cmds.e = 0;
}

void	move_player(t_main *cs)
{
//	reset_img(cs);
	int	test_dist;

	if (cs->cmds.n == 1)
	{
	//	test_dist = check_collision(cs, 'w');
		test_dist = check_wall(cs, STEP * sin(cs->pov.pov_ang * M_PI), STEP * -cos(cs->pov.pov_ang * M_PI));
		if (test_dist == 0)
		{
	//		printf("1	x: %.4f		y: %.4f\n", cs->ppos.x + cs->ppos.x_off, cs->ppos.y + cs->ppos.y_off);
			cs->ppos.x_off += STEP * sin(cs->pov.pov_ang * M_PI);
			cs->ppos.y_off += STEP * -cos(cs->pov.pov_ang * M_PI);
	//		printf("stepx: %.3f	stepy: %.3f\n", STEP * sin(cs->pov.pov_ang * M_PI), STEP * -cos(cs->pov.pov_ang * M_PI));
	//		printf("2	x: %.4f		y: %.4f\n", cs->ppos.x + cs->ppos.x_off, cs->ppos.y + cs->ppos.y_off);
		}
	//	else
	//		cs->ppos.y_off -= test_dist;
	}
	if (cs->cmds.w == 1)
	{
	//	test_dist = check_collision(cs, 'a');
		test_dist = check_wall(cs, STEP * sin((cs->pov.pov_ang - 0.5) * M_PI), STEP * -cos((cs->pov.pov_ang - 0.5)* M_PI));
		if (test_dist == 0)
		{
			cs->ppos.x_off += STEP * sin((cs->pov.pov_ang - 0.5) * M_PI);
			cs->ppos.y_off += STEP * -cos((cs->pov.pov_ang - 0.5) * M_PI);
		}
	//	else
	//		cs->ppos.x_off -= test_dist;
	}
	if (cs->cmds.s == 1)
	{
	//	test_dist = check_collision(cs, 's');
		test_dist = check_wall(cs, STEP * sin((cs->pov.pov_ang + 1) * M_PI), STEP * -cos((cs->pov.pov_ang + 1)* M_PI));
		if (test_dist == 0)
		{
			cs->ppos.x_off += STEP * sin((cs->pov.pov_ang + 1) * M_PI);
			cs->ppos.y_off += STEP * -cos((cs->pov.pov_ang + 1) * M_PI);
		}
	//	else
	//		cs->ppos.y_off += test_dist;
	}
	if (cs->cmds.e == 1)
	{
	//	test_dist = check_collision(cs, 'd');
		test_dist = check_wall(cs, STEP * sin((cs->pov.pov_ang + 0.5) * M_PI), STEP * -cos((cs->pov.pov_ang + 0.5)* M_PI));
		if (test_dist == 0)
		{
			cs->ppos.x_off += STEP * sin((cs->pov.pov_ang + 0.5) * M_PI);
			cs->ppos.y_off += STEP * -cos((cs->pov.pov_ang + 0.5) * M_PI);
		}
	//	else
	//		cs->ppos.x_off += test_dist;
	}
}

void	look_left(t_main *cs, int sens)
{
	cs->ppos.pov -= 0.01 * sens;
}

void    look_right(t_main *cs, int sens)
{
	cs->ppos.pov += 0.01 * sens;
}

void	look_up(t_main *cs, int sens)
{
	cs->ppos.z += sens;
}

void    look_down(t_main *cs, int sens)
{
	cs->ppos.z -= sens;
}

void	look(int key, t_main *cs)
{
//	reset_img(cs);	
	if (key == 12)
		cs->ppos.pov -= 0.04;
	else if (key == 14)
		cs->ppos.pov += 0.04;
}

void	change_weapon(int key, t_main *cs)
{
	if (key == 18)
		cs->ppos.hand = 1;
	else if (key == 19)
		cs->ppos.hand = 2;
	else if (key == 20)
		cs->ppos.hand = 3;
}

void	fire(t_main *cs)
{
	int	pid;

	if (cs->ppos.hand == 1)
	{
		pid = fork();
		if (pid == 0)
		{
			system("afplay -r 1.5 ./assets/sounds/ak_single_shot.wav");
			exit(0);
		}
	}
}
