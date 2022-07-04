#include "../inc/header.h"

int	closex(t_main *cs)
{
	(void)cs;
	exit(0);
}

int	press_binds(int key, t_main *cs)
{
	if (key == 53)
		exit(0);
	else if (key == 13 || key == 0 || key == 1 || key == 2)
		move_player(key, cs);
	else if (key == 12 || key == 14)
		look(key, cs);
	return (0);
}

void	controls(t_main *cs)
{
	mlx_hook(cs->data.mlx_win, 2, 0, press_binds, cs);
	mlx_hook(cs->data.mlx_win, 17, 0, closex, cs);
}
