#include "../inc/header.h"

int	closex(t_main *cs)
{
	(void)cs;
	exit(0);
}

int	mouse_mov(int x, int y, t_main *cs)
{
	(void)y;
	if (x != WIND_W/2 || y != WIND_H/2)
	{
		if (x > WIND_W/2)
			look_right(cs, (x - WIND_W/2) * SENSE);
		else if (x < WIND_W/2)
			look_left(cs, (WIND_W/2 - x) * SENSE);
	}
	mlx_mouse_move(cs->data.mlx_win, WIND_W/2, WIND_H/2);
	return (0);
}

int	mouse_controls(int button, int x, int y, t_main *cs)
{
	if (x >= 0 && x <= WIND_W && y >= 0 && y <= WIND_H)
	{
		if (button == 1)
			fire(cs);
	}
	return (0);
}

int	press_binds(int key, t_main *cs)
{
	if (key == 53)
		exit(0);
	else if (key == 13 || key == 0 || key == 1 || key == 2)
		active_mov(key, cs);
	else if (key == 12 || key == 14)
		look(key, cs);
	else if (key == 18 || key == 19 || key == 20)
		change_weapon(key, cs);
	return (0);
}

int	release_binds(int key, t_main *cs)
{
	if (key == 13 || key == 0 || key == 1 || key == 2)
		deactive_mov(key, cs);
	return (0);
}

void	controls(t_main *cs)
{
	mlx_mouse_hook(cs->data.mlx_win, mouse_controls, cs);
	mlx_hook(cs->data.mlx_win, 2, 0, press_binds, cs);
	mlx_hook(cs->data.mlx_win, 3, 0, release_binds, cs);
	mlx_hook(cs->data.mlx_win, 6, 0, mouse_mov, cs);
	mlx_hook(cs->data.mlx_win, 17, 0, closex, cs);
}
