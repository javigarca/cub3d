/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:44:46 by javi              #+#    #+#             */
/*   Updated: 2024/03/02 18:58:19 by javi             ###   ########.fr       */
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
			start.x += 6;
			end.x += 6;
			col++;
		}
		start.y += 6;
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
		ft_light_rect(gdata, start, end, MINI_CLR_F);
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

	start.x = (int)((data->player.pos.y) * MINI_SIZE) + origin.x;
	start.y = (int)((data->player.pos.x) * MINI_SIZE) + origin.y;
	ft_draw_circle(data, start, MINI_RADIUS, P40_CLR);
}

/** @brief 
* Draws a circle around a given coordinate and a given radius
* @param gdata game data structure
* @param center center of the circle, coordinate
* @param radius a raidus for such circle, in int
* @param color the color for the circle
*/

void	ft_draw_circle(t_gamedata *gdata, t_coord center, int radius, int color)
{
	int	x;
	int	y;

	y = center.y - radius;
	while (y <= center.y + radius)
	{
		x = center.x - radius;
		while (x <= center.x + radius)
		{
			if ((x - center.x) * (x - center.x) + (y - center.y) * \
					(y - center.y) <= radius * radius)
				ft_light_my_pixel(gdata, x, y, color);
			x++;
		}
		y++;
	}
}
