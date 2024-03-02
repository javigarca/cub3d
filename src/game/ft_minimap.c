/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:44:46 by javi              #+#    #+#             */
/*   Updated: 2024/03/02 10:24:55 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	ft_minimap_walls(t_gamedata *gdata, t_coord origin, int map_lines);
static void	ft_minimap_player(t_gamedata *data, t_coord origin);
static void	ft_minimap_walls_draw(char wall, t_gamedata *gdata, \
								t_coord start, t_coord end);

/**
 * Displays the minimap by drawing walls and player position
 * 
 * @param gdata Game data structure
 * @param origin Origin coordinates of the minimap
 */
void	ft_minimap(t_gamedata *gdata, t_coord origin)
{
	ft_minimap_walls(gdata, origin, ft_2d_array_size(gdata->map->map2d));
	ft_minimap_player(gdata, origin);
}

/**
 * Draws walls on the minimap based on the map data
 * 
 * @param gdata Game data structure
 * @param origin Origin coordinates of the minimap
 * @param map_lines Number of lines in the map
 */
static void	ft_minimap_walls(t_gamedata *gdata, t_coord origin, int map_lines)
{
	int		cont;
	int		col;
	t_coord	end;
	t_coord	start;

	cont = 0;
	start = origin;
	while (cont < map_lines)
	{
		col = 0;
		start.x = (int)origin.x;
		while (gdata->map->map2d[cont][col] != '\0')
		{
			end.y = start.y + 6;
			end.x = start.x + 6;
			ft_minimap_walls_draw(gdata->map->map2d[cont][col], \
									gdata, start, end);
			start.x += 7;
			end.x += 7;
			col++;
		}
		start.y += 7;
		cont++;
	}
}

/**
 * Draws walls on the minimap based on the wall type
 * 
 * @param wall Wall type ('1' for wall, '0' for empty space)
 * @param gdata Game data structure
 * @param start Starting coordinates of the wall
 * @param end Ending coordinates of the wall
 */
static void	ft_minimap_walls_draw(char wall, t_gamedata *gdata, \
								t_coord start, t_coord end)
{
	if (wall == '1')
		ft_light_rect(gdata, start, end, MINI_CLR_W);
	if (wall == '0')
		ft_light_rect(gdata, start, end, MINI_CLR_F);
	if (wall == 'N' || wall == 'S' || wall == 'E' || wall == 'W')
		ft_light_rect(gdata, start, end, P10_CLR);
}

/**
 * Draws a light rectangle at the player's position on the minimap
 * 
 * @param data Game data structure
 * @param origin Origin coordinates of the minimap
 */
static void	ft_minimap_player(t_gamedata *data, t_coord origin)
{
	t_coord	start;
	t_coord	end;

	start.x = (int)((data->player.pos.y) * 6) + origin.x;
	start.y = (int)((data->player.pos.x) * 6) + origin.y;
	end.x = start.x + 5;
	end.y = start.y + 5;
	ft_light_rect(data, start, end, P30_CLR);
}
