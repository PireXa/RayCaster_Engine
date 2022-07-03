#include "../inc/header.h"

float	dist_player_wall(float x1, float y1, int x2, int y2)
{
	return (sqrt(pow(fabs(x2 - x1), 2) + pow(fabs(y2 - y1), 2)));
}

void	build_raycasting(t_main *cs, int x, float dist)
{
	int	render_h;			//Height of the wall on the 3d representation
//	int	left_dist;
//	int	wall_height;
	int	y;				//Start position for the render
	int	antiali;
	int	y_res;

	antiali = -3;
//	left_dist = MAX_DIST - dist;
//	wall_height = WALL_HEIGHT;
//	render_h = left_dist * (wall_height / MAX_DIST);
	render_h = (32 * WIND_H) / dist;
//	printf("dist: %.3f         render_h: %d\n\n", dist, render_h);
//	y = (WIND_H / 2) - (render_h / 2);
	y = 360 - (render_h/2);
	y_res = y;
	while (++antiali < 3)
	{
		while (y < y_res + render_h)
		{
			put_pxl(&cs->rc, x + antiali, y, WALL_COLOR);
			y++;
		}
		y = y_res;
	}
}

void	render_3d(t_main *cs, float pov_ang, float ray_ang, float x1, float y1, int x2, int y2)
{
	float		d_pl_w;			//distance from the player to the wall in the direction of the ray
	float		d_pl_sc;		//distance from the player to the plane perpendicular to the player crosshair ray,
						//containing the hit point of the ray on the wall
	int		r_step;			//Distance between rays on the screen
	float		dif_ang;
	int		rc_x;			//X coordinate of the casted ray on the screen
	float		step_ang;

	d_pl_w = dist_player_wall(x1, y1, x2, y2);
//	printf("x1: %.2f    y1: %.2f   x2: %d    y2: %d\ndist: %d\n", x1, y1, x2, y2, d_pl_w);
//	printf("ray_ang: %.3f       pov_ang: %.3f\n", ray_ang, pov_ang);
//	printf("cos: %.3f\n", cos((ray_ang - pov_ang) * M_PI));
	d_pl_sc = d_pl_w * cos((ray_ang - pov_ang) * M_PI);
//	printf("dist to wall: %.3f          dist to screen: %.3f\n", d_pl_w, d_pl_sc);
//RAYS casting from middle to the right and then middle to the left
	r_step = WIND_W / RAY_NUM;
	dif_ang = ray_ang - pov_ang;
//	printf("dif_ang: %.3f\n", dif_ang);
	step_ang = POV / (RAY_NUM - 1);
	rc_x = (WIND_W / 2) + r_step * (dif_ang / step_ang);
	build_raycasting(cs, rc_x, d_pl_sc);
}
