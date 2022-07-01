#ifndef HEADER_H
#define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <ctype.h>

# define BUFFER_SIZE 10
# define WIND_H 720
# define WIND_W 1080

typedef	struct	s_img {
	char    *addr;
	int     bi_per_pxl;
	int     line_length;
	int     endian;
}		t_img;

typedef struct s_wind {
        void 	*mlx;
        void	*mlx_win;
        void	*img;
}             t_wind;

typedef struct	s_p_pos {
	int	x;
	int	y;
	int	x_off;
	int     y_off;
}		t_p_pos;

typedef struct s_main {
        t_wind   data;
        t_p_pos ppos;
}               t_main;

//PLAYER MOVEMENT

t_main *pos_init(void);

void	move_player(t_main *cs);

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


//GRAPHIC FUNCTIONS

void	put_pxl(t_wind *img, int x, int y, int color);

t_wind   initialize_wind();

t_p_pos	draw_minimap(t_wind img, char **map);

void	draw_player_pos(t_main *cs);

//CONTROLS

void	controls(t_main *cs);

#endif
