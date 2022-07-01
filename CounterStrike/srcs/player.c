#include "../inc/header.h"

void	draw_player_pos(t_main *cs)
{
	int	i;
	int	e;

	i = -1;
	e = -1;
	while (++i < PLAYER_SCALE)
	{
		while (++e < PLAYER_SCALE)
		{
			put_pxl(&cs->p, i, e, 0x0000ff);
		}
		e = -1;
	}
}
