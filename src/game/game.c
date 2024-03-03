/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:27:03 by javigarc          #+#    #+#             */
/*   Updated: 2024/03/02 20:08:58 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	ft_gamedata_init(t_gamedata *gdata);
static void	ft_init_player(t_gamedata *gdata);
static void	ft_init_player_direction(t_gamedata *gdata, char dir);

int	start_the_game(t_data *valmap, char *level)
{
	t_gamedata	gdata;

	gdata.map = valmap;
	gdata.map_name = level;
	ft_gamedata_init(&gdata);
	//ft_game_start_screen(&gdata);
	ft_load_textures(&gdata);
	ft_start_draw(&gdata);
	ft_start_hooks(&gdata);
	ft_show_minimap(&gdata);
	mlx_loop(gdata.mlx);
	return (0);
}

static void	ft_gamedata_init(t_gamedata *gdata)
{
	gdata->mlx = mlx_init();
	gdata->win_size.x = W_RESOL;
	gdata->win_size.y = H_RESOL;
	gdata->img_size.x = W_RESOL;
	gdata->img_size.y = H_RESOL;
	ft_init_player(gdata);
	gdata->win = mlx_new_window(gdata->mlx, gdata->win_size.x, \
			gdata->win_size.y, "[*]----:*:-^-[CUB3D]-^-:*:----[*]");
	gdata->img = mlx_new_image(gdata->mlx, gdata->img_size.x, \
			gdata->img_size.y);
	gdata->imgadd = mlx_get_data_addr(gdata->img, &gdata->pixel_b, \
			&gdata->lines_b, &gdata->endian);
	//gdata->pause = TRUE;
	gdata->pause = FALSE;
}

static void	ft_init_player(t_gamedata *gdata)
{
	char	initdir;

	initdir = gdata->map->map2d[gdata->map->p_x][gdata->map->p_y];
	gdata->player.dir.x = 0;
	gdata->player.dir.y = 0;
	gdata->player.plane.x = 0;
	gdata->player.plane.y = 0;
	gdata->player.pitch = 0;
	ft_init_player_direction (gdata, initdir);
	gdata->player.pos.x = gdata->map->p_x + OFFSET;
	gdata->player.pos.y = gdata->map->p_y + OFFSET;
}

static void	ft_init_player_direction(t_gamedata *gdata, char dir)
{
	if (ft_strncmp(&dir, "N", 1) == 0)
	{
		gdata->player.dir.x = -1;
		gdata->player.plane.y = 0.66;
	}
	if (ft_strncmp(&dir, "E", 1) == 0)
	{
		gdata->player.dir.y = 1;
		gdata->player.plane.x = 0.66;
	}
	if (ft_strncmp(&dir, "S", 1) == 0)
	{
		gdata->player.dir.x = 1;
		gdata->player.plane.y = -0.66;
	}
	if (ft_strncmp(&dir, "W", 1) == 0)
	{
		gdata->player.dir.y = -1;
		gdata->player.plane.x = -0.66;
	}
}
