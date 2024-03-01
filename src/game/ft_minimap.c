/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:44:46 by javi              #+#    #+#             */
/*   Updated: 2024/03/01 19:54:50 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_minimap(t_gamedata *gdata, t_coord origin)
{
	int	cont;
	int	col;
	int	map_lines;
	t_coord end;
	t_coord start;

	cont = 0;
//	start.x = (int)origin.x;
	map_lines = ft_2d_array_size(gdata->map->map2d);
	while (cont < map_lines)
	{
		col = 0;
		start.x = (int)origin.x;
    	while (gdata->map->map2d[cont][col] != '\0')
		{
			end.y = start.y + 6; 
			end.x = start.x + 6;
			if (gdata->map->map2d[cont][col] == '1')
				ft_light_rect(gdata, start, end, MINI_CLR_W);
			else 
				ft_light_rect(gdata, start, end, MINI_CLR_F);
			start.x += 7;
			end.x += 7;
			col++;
		}
//		start.x = (int)origin.x;
		start.y += 7;
		cont++;
	}
	start.x = (int)((gdata->player.pos.y) * 6) + origin.x;
	start.y = (int)((gdata->player.pos.x) * 6) + origin.y;
	end.x = start.x + 6;
	end.y = start.y + 6;
	ft_light_rect(gdata, start, end, P30_CLR);
}

