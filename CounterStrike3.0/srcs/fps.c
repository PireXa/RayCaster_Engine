#include "../inc/header.h"

void	count_fps(t_main *cs)
{
	char *fps;
	char *fps_text;

	if (cs->fps.time < time(NULL))
	{
		cs->fps.fps = cs->fps.frame_ctr;
		cs->fps.frame_ctr = 0;
		cs->fps.time = time(NULL);
	}
	fps = ft_itoa(cs->fps.fps);
	fps_text = ft_strjoin("FPS: ", fps);
	mlx_string_put(cs->data.mlx, cs->data.mlx_win, WIND_W - 60, 15, 0x000000, fps_text);
	free(fps);
	free(fps_text);
	cs->fps.frame_ctr++;
}
