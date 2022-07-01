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
	else if (key == 13)
		move_player(cs);
	return (0);
}

void	controls(t_main *cs)
{
	mlx_hook(cs->img.mlx_win, 2, 0, press_binds, cs);
	mlx_hook(cs->img.mlx_win, 17, 0, closex, cs);
}
