/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:45 by javigarc          #+#    #+#             */
/*   Updated: 2024/02/27 11:32:11 by xamayuel         ###   ########.fr       */
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



# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4	// player speed

typedef struct s_dot
{
	int	x;
	int	y;
}			t_dot;

typedef struct	s_coord
{	
	double	x;
	double	y;
}				t_coord;
typedef struct s_player
{
    t_coord pos; // Posición del jugador
    t_coord dir; // Dirección de la vista del jugador
    t_coord plane; // El plano de la cámara, perpendicular a la dirección de la vista
} t_player;

typedef struct	s_raysdt
{
	int 	pix;
	t_coord	delta;
	t_coord sidedist;
	t_coord posray;
	t_dot	map;
	t_coord step;
	int 	stepSize;
	t_coord	dir;
	double	camerax;
	int		wallhit;
	double	walldist;
	double	wallheight;
	int		side;
	int		start;
	int		end;
}				t_raysdt;

typedef struct s_gamedata
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*imgadd;
	int		pixel_b;
	int		lines_b;
	int		endian;
	char	*map_name;
	t_data	*map;
	//t_mods	hookmods;
	t_dot	win_size;
	t_dot	img_size;
	t_player	player;
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
int ft_to_color_argb(t_color color);
//
void  ft_raycasting(t_gamedata *gdata);
#endif
