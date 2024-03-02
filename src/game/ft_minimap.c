/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:44:46 by javi              #+#    #+#             */
/*   Updated: 2024/03/02 10:16:25 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	ft_minimap_player(t_gamedata *data, t_coord origin);

void	ft_minimap_walls_draw(char wall, t_gamedata *gdata, \
								t_coord start, t_coord end)
{
	if (wall == '1')
		ft_light_rect(gdata, start, end, MINI_CLR_W);
	if (wall == '0')
		ft_light_rect(gdata, start, end, MINI_CLR_F);
}

void	ft_minimap_walls(t_gamedata *gdata, t_coord origin, int map_lines)
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

void	ft_minimap(t_gamedata *gdata, t_coord origin)
{
	ft_minimap_walls(gdata, origin, ft_2d_array_size(gdata->map->map2d));
	ft_minimap_player(gdata, origin);
}

static void	ft_minimap_player(t_gamedata *data, t_coord origin)
{
	t_coord	start;
	t_coord	end;

	start.x = (int)((data->player.pos.y) * MINI_SIZE) + origin.x;
	start.y = (int)((data->player.pos.x) * MINI_SIZE) + origin.y;
	end.x = start.x + 6;
	end.y = start.y + 6;
	ft_light_rect(data, start, end, P30_CLR);
}
