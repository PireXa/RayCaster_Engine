#include "../inc/header.h"

void	draw_rays2D(t_main *cs)
{
//	float	ray_ang;
	int	dx;
	int	dy;
	int	cur_x;
	int	cur_y;
//	float	pov_ang;
//	float	pov_cap;
//	float	step_ang;

	cs->pov.pov_ang = 0 + cs->ppos.pov;
	cs->pov.ray_ang = cs->pov.pov_ang;
	cs->pov.pov_cap = cs->pov.pov_ang + (POV / 2);
	cs->pov.step_ang = POV / (RAY_NUM - 1);
	cur_x = cs->ppos.x + cs->ppos.x_off;
	cur_y = cs->ppos.y + cs->ppos.y_off;
//	dy = -cos(ang * M_PI) * RAY_LENGTH;
//	dx = sin(ang * M_PI) * RAY_LENGTH;
//	ray_drawer(cur_x, cur_y, cur_x + dx, cur_y + dy, cs->map, cs);
//	printf("RIGHT RAYS\n");
	while (cs->pov.ray_ang <= cs->pov.pov_cap)
	{
		dy = -cos(cs->pov.ray_ang * M_PI) * RAY_LENGTH;
		dx = sin(cs->pov.ray_ang * M_PI) * RAY_LENGTH;
//		printf("NEXT RAY\n");
		ray_drawer(cur_x, cur_y, cur_x + dx, cur_y + dy, cs->map, cs);
		cs->pov.ray_ang += cs->pov.step_ang;
	}
//	printf("LEFT RAYS\n");
	cs->pov.ray_ang = cs->pov.pov_ang - cs->pov.step_ang;
	cs->pov.pov_cap = cs->pov.pov_ang - (POV / 2);
	while (cs->pov.ray_ang >= cs->pov.pov_cap)
	{
		dy = -cos(cs->pov.ray_ang * M_PI) * RAY_LENGTH;
		dx = sin(cs->pov.ray_ang * M_PI) * RAY_LENGTH;
	//	printf("NEXT RAY\n");
		ray_drawer(cur_x, cur_y, cur_x + dx, cur_y + dy, cs->map, cs);
		cs->pov.ray_ang -= cs->pov.step_ang;
	}

}
