/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door_system.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:03:25 by javi              #+#    #+#             */
/*   Updated: 2024/03/02 23:26:47 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_door_system(t_gamedata *gdata, double distance)
{
	t_coord	new;

	new.x = gdata->player.pos.x + gdata->player.dir.x * distance;
	new.y = gdata->player.pos.y + gdata->player.dir.y * distance;
	ft_toogle_door(gdata->map, new);
	return (0);
}

int	ft_toogle_door(t_data *map, t_coord new)
{
	int	x;
	int	y;

	x = (int)new.x;
	y = (int)new.y;
	if (map->map2d[x][y] == '3')
		map->map2d[x][y] = '2';
	else if (map->map2d[x][y] == '2')
		map->map2d[x][y] = '3';
	return (0);
}
