#ifndef HEADER_H
#define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <ctype.h>

# define BUFFER_SIZE	10
# define WIND_H		720
# define WIND_W		1080
# define MINIMAP_X	25
# define MINIMAP_Y	15
# define MAP_SCALE	21	//41
# define PLAYER_SCALE	11	//11
# define RAY_LENGTH	350	
# define STEP		2	//5
# define PLAYER_COLOR	0x0000ff
# define WALL_COLOR	0x6a6a6a
# define FLOOR_COLOR	0x76f6d3
# define RAY_COLOR	0xff0000
# define POV		0.5
# define RAY_NUM	251
# define MAX_DIST	700
# define WALL_HEIGHT	320

typedef	struct	s_img {
	void	*img;
	char    *addr;
	int     bi_per_pxl;
	int     line_length;
	int     endian;
}		t_img;

typedef struct s_wind {
        void 	*mlx;
        void	*mlx_win;
}             t_wind;

typedef struct	s_p_pos {
	int	x;
	int	y;
	int	x_off;
	int     y_off;
	float	pov;
}		t_p_pos;

typedef struct s_main {
        t_wind   data;
	t_img	map;
	t_img	p;
	t_img	rc;
        t_p_pos ppos;
	char	**mapdata;
}               t_main;

typedef struct s_counters {
	int	i;
	int	e;
}		t_counters;

//UTILS

void    ft_bzero(void *s, size_t len);

void    *ft_memset(void *dest, int val, size_t len);

//PLAYER MOVEMENT

t_main *pos_init(void);

void	move_player(int key, t_main *cs);

void    look(int key, t_main *cs);

//MAP READING FUNCTIONS

char	**mapfile_reader(char *map);

char	*ft_strchr(const char *s, int c);

char	*ft_exstrchr(char *s);

size_t	ft_strlen(const char *str);

char	*ft_strnldup(char *s1);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strnnldup(char *s1);

char	*get_next_line(int fd);

size_t	ft_strlcpy(char *dst, char *src, size_t size);

char    **ft_split(char const *s, char c);

t_counters      p_position_on_map(int x, int y);

//GRAPHIC FUNCTIONS

void    reset_img(t_main *cs);

void	put_pxl(t_img *img, int x, int y, int color);

t_wind	initialize_wind();

void    img_initializer(t_main *cs);

void	draw_minimap(t_main *cs);

void	draw_player_pos(t_main *cs);

void	image_to_window(t_main *cs);

void	draw_rays2D(t_main *cs);

void    ray_drawer(float pov_ang, float ray_ang, float x1, int y1, int x2, int y2, t_img img, t_main *cs);

void    render_3d(t_main *cs, float pov_ang, float ray_ang, float x1, float y1, int x2, int y2);

//CONTROLS

void	controls(t_main *cs);

#endif
