#include "../inc/header.h"

void	draw_rays2D(t_main *cs)
{
	float	ang;
	int	dx;
	int	dy;
	int	cur_x;
	int	cur_y;

	ang = 0.75 + cs->ppos.pov;
	cur_x = cs->ppos.x + cs->ppos.x_off;
	cur_y = cs->ppos.y + cs->ppos.y_off;
	dy = -cos(ang * M_PI) * RAY_LENGTH;
	dx = sin(ang * M_PI) * RAY_LENGTH;
//	printf("dy = %d\n", dy);
//	printf("dx = %d\n", dx);
	ray_drawer(cur_x, cur_y, cur_x + dx, cur_y + dy, cs->map);
/*	while (ang <= 30.3 + cs->ppos.pov)
	{
		dy = -cos(ang * M_PI) * RAY_LENGTH;
		dx = sin(ang * M_PI) * RAY_LENGTH;
		ray_drawer(cur_x, cur_y, cur_x + dx, cur_y + dy, cs->map);
		ang += 0.02;
	}
	ang = 30 + cs->ppos.pov;
	while (ang >= 29.7 + cs->ppos.pov)
	{
		dy = -cos(ang * M_PI) * RAY_LENGTH;
		dx = sin(ang * M_PI) * RAY_LENGTH;
		ray_drawer(cur_x, cur_y, cur_x + dx, cur_y + dy, cs->map);
		ang -= 0.02;
	}
*/
}
