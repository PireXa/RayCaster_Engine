SRCS		=	main.c initializers.c get_next_line.c \
			get_next_line_utils.c mapfile_reader.c ft_strdup.c \
			draw_minimap.c controls.c player.c ctrl_handler1.c \
			ft_bzero.c ft_memset.c ft_strcmp.c ft_itoa.c img_to_wind.c rays2d.c \
			ray_drawer.c 3D_render.c draw_floor_ceiling.c \
			crosshair.c fps.c xpm_to_image.c \

OBJS		=	$(addprefix objs/,$(SRCS:.c=.o))

CFLAGS		= 	-Wall -Wextra -Werror -g

RM		=	rm -f

NAME		=	CountereSeteraique

all:		$(NAME)

objs/%.o: srcs/%.c
			@mkdir -p objs
			@$(CC) $(CFLAGS) -I/inc/header.h -Imlx -c $< -o $@

$(NAME): 	$(OBJS)
			@cc $(OBJS) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:		fclean all
