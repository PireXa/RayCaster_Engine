#include "../inc/header.h"

t_map_d get_map_dimensions(char **map)
{
	int	i;
	int	e;
	int	rec_e;
	t_map_d	map_d;

	i = -1;
	e = -1;
	rec_e = 0;
	while (map[++i])
	{
		while (map[i][++e]);
		if (e > rec_e)
			rec_e = e;
		e = -1;
	}
	i--;
	rec_e--;
	map_d.x = rec_e;
	map_d.y = i;
	return(map_d);
}

int	lenght_ctr(char *map_path)
{
	int	ctr;
	int	fd;
	char	*line;

	ctr = 2;
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		line = get_next_line(fd);
		ctr++;
	}
	close(fd);
	return(ctr);
}

char	**mapfile_reader(char *raw_map)
{
	char	**map;
	char	*map_path;
	char	*tmp;
	int	fd;
	int	i = -1;

	map_path = ft_strjoin("maps/", raw_map);
	map = (char **)malloc(sizeof(char *) * lenght_ctr(map_path));
	fd = open(map_path, O_RDONLY);
	free(map_path);
	tmp = get_next_line(fd);
	while (tmp)
	{
		map[++i] = ft_strnnldup(tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	map[++i] = NULL;
	free(tmp);
	close(fd);
	return(map);
}
