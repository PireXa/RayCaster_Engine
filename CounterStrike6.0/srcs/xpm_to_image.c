#include "../inc/header.h"

t_img	converter(t_main *cs, char *img)
{
	t_img   xpm;

	if (!ft_strcmp(img, "ak"))
	{
		xpm.img = mlx_xpm_file_to_image(cs->data.mlx, "./assets/skins/ak_vulcan_kato2014.xpm", &cs->ass.ak.x, &cs->ass.ak.y);
		
		return(xpm);
	}
	else if (!ft_strcmp(img, "m9"))
	{
		xpm.img = mlx_xpm_file_to_image(cs->data.mlx, "./assets/skins/huntsman_tiger_tooth.xpm", &cs->ass.m9.x, &cs->ass.m9.y);
		return (xpm);
	}
	else if (!ft_strcmp(img, "deagle"))
	{
		xpm.img = mlx_xpm_file_to_image(cs->data.mlx, "./assets/skins/deagle.xpm", &cs->ass.deagle.x, &cs->ass.deagle.y);
		return(xpm);
	}
	exit(0);
}

void	get_assets(t_main *cs)
{
	cs->ass.ak = converter(cs, "ak");
	cs->ass.m9 = converter(cs, "m9");
	cs->ass.deagle = converter(cs, "deagle");
}


