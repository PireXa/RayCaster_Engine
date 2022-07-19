#include "../inc/header.h"

void	jump(t_main *cs)
{
	long long	curr_time;
	int		air_time;
	float		j_speed;

	if (cs->ppos.j.j_time == -1)
		return;
	else
	{
		j_speed = 0.1;
		curr_time = current_timestamp();
		air_time = curr_time - cs->ppos.j.j_time;
		cs->ppos.j.height = j_speed * air_time * 1000 - ((GRAVITY * pow(air_time, 2)) / 2);
		if (cs->ppos.j.height <= 0)
		{
			cs->ppos.j.j_time = -1;
			cs->ppos.j.height = 0;
		}
	}
}
