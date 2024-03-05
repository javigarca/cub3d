/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sky_floor_draw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:13:04 by javi              #+#    #+#             */
/*   Updated: 2024/03/05 21:54:56 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/**
 * Draw the sky and floor in the game window.
 * 
 * @param gdata The game data structure
 */
void	ft_sky_floor_draw(t_gamedata *gdata)
{
	t_coord	start;
	t_coord	end;

	start.x = 0;
	start.y = 0;
	end.x = gdata->img_size.x;
	end.y = gdata->img_size.y / 2 + gdata->player.pitch;
	ft_light_rect(gdata, start, end, ft_to_color_argb(gdata->map->c_celing));
	start.y = end.y;
	end.y = gdata->img_size.y;
	ft_light_rect(gdata, start, end, ft_to_color_argb(gdata->map->c_floor));
}
