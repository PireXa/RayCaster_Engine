#include "../inc/header.h"

void	draw_rays2D(t_main *cs)
{
	float	ray_ang;
	int	dx;
	int	dy;
	int	cur_x;
	int	cur_y;
	float	pov_ang;
	float	pov_cap;
	float	step_ang;

	pov_ang = 0 + cs->ppos.pov;
	ray_ang = pov_ang;
	pov_cap = pov_ang + (POV / 2);
	step_ang = POV / (RAY_NUM - 1);
	cur_x = cs->ppos.x + cs->ppos.x_off;
	cur_y = cs->ppos.y + cs->ppos.y_off;
//	dy = -cos(ang * M_PI) * RAY_LENGTH;
//	dx = sin(ang * M_PI) * RAY_LENGTH;
//	ray_drawer(cur_x, cur_y, cur_x + dx, cur_y + dy, cs->map, cs);
//	printf("RIGHT RAYS\n");
	while (ray_ang <= pov_cap)
	{
		dy = -cos(ray_ang * M_PI) * RAY_LENGTH;
		dx = sin(ray_ang * M_PI) * RAY_LENGTH;
//		printf("NEXT RAY\n");
		ray_drawer(pov_ang, ray_ang, cur_x, cur_y, cur_x + dx, cur_y + dy, cs->map, cs);
		ray_ang += step_ang;
	}
//	printf("LEFT RAYS\n");
	ray_ang = pov_ang - step_ang;
	pov_cap = pov_ang - (POV / 2);
	while (ray_ang >= pov_cap)
	{
		dy = -cos(ray_ang * M_PI) * RAY_LENGTH;
		dx = sin(ray_ang * M_PI) * RAY_LENGTH;
	//	printf("NEXT RAY\n");
		ray_drawer(pov_ang, ray_ang, cur_x, cur_y, cur_x + dx, cur_y + dy, cs->map, cs);
		ray_ang -= step_ang;
	}

}
