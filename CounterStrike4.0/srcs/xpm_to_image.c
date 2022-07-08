#include "../inc/header.h"

t_img	converter(t_main *cs, char *img)
{
	t_img   ak;

	if (!ft_strcmp(img, "ak"))
	{
		ak.img = mlx_xpm_file_to_image(cs->data.mlx, "./assets/skins/ak.xpm", &ak.x, &ak.y);
		
		return (ak);
	}
	else if (!ft_strcmp(img, "m9"))
	{
		ak.img = mlx_xpm_file_to_image(cs->data.mlx, "./assets/skins/m9.xpm", &cs->ass.m9.x, &cs->ass.m9.y);
		return (ak);
	}
	exit(0);
}

void	get_assets(t_main *cs)
{
	cs->ass.ak = converter(cs, "ak");
	cs->ass.m9 = converter(cs, "m9");
}


