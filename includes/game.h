/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:45 by javigarc          #+#    #+#             */
/*   Updated: 2024/02/29 10:13:33 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define DEF_CLR 0xE2E270
# define P10_CLR 0x1915FF
# define P20_CLR 0x6D00AF
# define P30_CLR 0xCB00BF
# define P40_CLR 0xFF066A
# define P50_CLR 0xFF671D
# define P60_CLR 0xFCFF6D
# define P70_CLR 0xAEFF95
# define P80_CLR 0x98FFE6
# define P90_CLR 0xB3E6FF
# define P00_CLR 0xFDFDFD
# define BKG_CLR_A 0x151515
# define BKG_CLR_B 0x303030
# define TXT_CLR_A 0xF7F7DA
# define TXT_CLR_B 0xAC0FAC

// defines para gestion de texturas
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
//

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include "game_struct.h"
# include "mlx.h"
# if defined(__APPLE__)
#  include <key_macos.h>
# else
#  include <key_linux.h>
# endif

# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED 0.1 // rotation speed
# define MOVE_SPEED 0.25	// player speed
# define STRAFE_SPEED 0.25	// player strafe speed
# define OFFSET .2 // para el buffer de colision

typedef struct s_dot
{
	int	x;
	int	y;
}			t_dot;

typedef struct s_coord
{
	double	x;
	double	y;
}				t_coord;
typedef struct s_player
{
	t_coord	pos; // Posición del jugador
	t_coord	dir; // Dirección de la vista del jugador
	t_coord	plane;	// El plano de la cámara.
	double	rot_angle; // Ángulo de rotación del jugador
}	t_player;

typedef struct s_raysdt
{
	int		pix;	// Índice del píxel actual en el eje X
	t_coord	delta; // Distancia a mover en el mapa por cada paso en X o Y
	t_coord	sidedist; // Distancia al próximo lado en X o Y
	t_coord	posray; // Posición actual del rayo
	t_dot	map; // Coordenadas del mapa en el que se encuentra el rayo
	t_coord	step; // Dirección del paso en X o Y (1 o -1)
	int		stepSize; // Tamaño del paso
	t_coord	dir; // Dirección del rayo
	double	camerax; // Posición X de la cámara en el espacio de la cámara
	int		wallhit; // Indica si el rayo ha golpeado una pared
	double	walldist; // Distancia desde jugador hasta la pared golpeada
	double	wallheight; // Altura de la pared golpeada
	int		side; // Lado de la pared golpeada (Norte, Sur, Este, Oeste)
	int		start; // Punto de inicio para el dibujo de la pared en la pantalla
	int		end; // Punto final para el dibujo de la pared en la pantalla
	double	wallX; // where exactly the wall was hit
	double	texpos;
	int		texX; // x coordinate on the texture
	int		texY;
	int		stripStart;
	int		stripEnd;
	int		pitch;
	double	texture_step;
}				t_raysdt;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;

}	t_img;
typedef struct s_gamedata
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	char		*imgadd;
	int			pixel_b;
	int			lines_b;
	int			endian;
	char		*map_name;
	t_data		*map;
	t_dot		win_size;
	t_dot		img_size;
	t_player	player;
	int			**textures;
	int			size;
}			t_gamedata;

/// game.c///
int		start_the_game(t_data *validatedmap, char *level);
//
void	ft_start_hooks(t_gamedata *gdata);
//
void	ft_show_menu(t_gamedata *gdata, char *line);
//
void	ft_start_draw(t_gamedata *gdata);
//
int		ft_to_color_argb(t_color color);
//
void	ft_raycasting(t_gamedata *gdata);
//
void	ft_draw_ray_wall(t_gamedata *gdata, t_raysdt *ray, int color);
//
void	ft_load_textures(t_gamedata *gdata);
//
void	ft_rotate_player(t_gamedata *gdata, double rot_speed);
void	ft_strafe_left(t_gamedata *gdata, double strafe_speed);
void	ft_strafe_right(t_gamedata *gdata, double strafe_speed);
void	ft_move_forward(t_gamedata *gdatar, double strafe_speed);
void	ft_move_backwards(t_gamedata *gdata, double strafe_speed);
//
int		ft_check_collision(t_data *map, t_coord new);
int		ft_check_doble_col(t_data *map, t_coord new);
#endif
