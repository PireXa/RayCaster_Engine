#include "../inc/header.h"

float	dist_player_wall(float x1, float y1, int x2, int y2)
{
	return (sqrt(pow(fabs(2 * (x2 - x1)), 2) + pow(fabs(2 * (y2 - y1)), 2)));
}

int	get_wall_color(int w_type)
{
	if (w_type == 1)
		return(N_WALL_COLOR);	//RED
	else if (w_type == 2)
		return(E_WALL_COLOR);	//GREEN
	else if (w_type == 3)
		return(S_WALL_COLOR);	//ORANGE
	else
		return(W_WALL_COLOR);	//BLUE
}

void	build_raycasting(t_main *cs, int x, float dist, int w_type)
{
	int	render_h;			//Height of the wall on the 3d representation
//	int	left_dist;
//	int	wall_height;
	int	y;				//Start position for the render
//	int	antiali;
	int	y_res;
	int	clr;

//	antiali = -3;
	clr = get_wall_color(w_type);

//	left_dist = MAX_DIST - dist;
//	wall_height = WALL_HEIGHT;
//	render_h = left_dist * (wall_height / MAX_DIST);

	render_h = (32 * WIND_H) / (dist);

//	printf("dist: %.3f         render_h: %d\n\n", dist, render_h);
	y = (WIND_H / 2) - (render_h/2);
	y_res = y;
//	while (++antiali < 3)
//	{
		while (y < y_res + render_h)
		{
			put_pxl(&cs->rc, x /*+ antiali*/, y, clr);
			y++;
		}
//		y = y_res;
//	}
}

void	render_3d(t_main *cs, float x1, float y1, float x2, float y2, int w_type)
{
	float		d_pl_w;			//distance from the player to the wall in the direction of the ray
	float		d_pl_sc;		//distance from the player to the plane perpendicular to the player crosshair ray,
						//containing the hit point of the ray on the wall
	float		r_step;			//Distance between rays on the screen
	float		dif_ang;
	int		rc_x;			//X coordinate of the casted ray on the screen
	float		step_ang;

//	printf("x1: %.3f	y1: %.3f	x2: %.3f	y2: %.3f\n", x1, y1, x2, y2);
	d_pl_w = dist_player_wall(x1, y1, x2, y2);
//	printf("d: %.4f\n", d_pl_w);
	dif_ang = cs->pov.ray_ang - cs->pov.pov_ang;
	d_pl_sc = d_pl_w * cos((dif_ang) * M_PI);
//RAYS casting from middle to the right and then middle to the left
//	r_step = WIND_W / (RAY_NUM - 1);// - 1);
	r_step = 1;
	step_ang = POV / (RAY_NUM - 1);// - 1);
	rc_x = (WIND_W / 2) + r_step * (dif_ang / step_ang);
//	printf("rc_x: %d\n", rc_x);
	build_raycasting(cs, rc_x, d_pl_sc, w_type);
}
