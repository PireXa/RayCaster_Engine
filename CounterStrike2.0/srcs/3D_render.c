#include "../inc/header.h"

float	dist_player_wall(float x1, float y1, int x2, int y2)
{
	return (sqrt(pow(fabs(x2 - x1), 2) + pow(fabs(y2 - y1), 2)));
}

int	get_wall_color(int w_type)
{
	if (w_type == 1)
		return(0xff0000);	//RED
	else if (w_type == 2)
		return(0x00ff00);	//GREEN
	else if (w_type == 3)
		return(0xffaa00);	//ORANGE
	else
		return(0x0000ff);	//BLUE
}

void	build_raycasting(t_main *cs, int x, float dist, int w_type)
{
	int	render_h;			//Height of the wall on the 3d representation
//	int	left_dist;
//	int	wall_height;
	int	y;				//Start position for the render
	int	antiali;
	int	y_res;
	int	clr;

	antiali = -4;
	clr = get_wall_color(w_type);
//	left_dist = MAX_DIST - dist;
//	wall_height = WALL_HEIGHT;
//	render_h = left_dist * (wall_height / MAX_DIST);
	render_h = (32 * WIND_H) / dist;
//	printf("dist: %.3f         render_h: %d\n\n", dist, render_h);
//	y = (WIND_H / 2) - (render_h / 2);
	y = 360 - (render_h/2);
	y_res = y;
	while (++antiali < 4)
	{
		while (y < y_res + render_h)
		{
			put_pxl(&cs->rc, x + antiali, y, clr);
			y++;
		}
		y = y_res;
	}
}

void	render_3d(t_main *cs, float x1, float y1, int x2, int y2, int w_type)
{
	float		d_pl_w;			//distance from the player to the wall in the direction of the ray
	float		d_pl_sc;		//distance from the player to the plane perpendicular to the player crosshair ray,
						//containing the hit point of the ray on the wall
	int		r_step;			//Distance between rays on the screen
	float		dif_ang;
	int		rc_x;			//X coordinate of the casted ray on the screen
	float		step_ang;

	d_pl_w = dist_player_wall(x1, y1, x2, y2);
	dif_ang = cs->pov.ray_ang - cs->pov.pov_ang;
	d_pl_sc = d_pl_w * cos((dif_ang) * M_PI);
//RAYS casting from middle to the right and then middle to the left
	r_step = WIND_W / (RAY_NUM * 0.75);
//	r_step = 5;
	step_ang = POV / (RAY_NUM - 1);
	rc_x = (WIND_W / 2) + r_step * (dif_ang / step_ang);
	build_raycasting(cs, rc_x, d_pl_sc, w_type);
}
