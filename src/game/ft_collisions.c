/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collisions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:41:12 by javi              #+#    #+#             */
/*   Updated: 2024/03/02 09:46:10 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/**
 * Check if there is a collision at the X coordinate in the map
 * 
 * @param map The game map
 * @param newX The new x coordinate to check
 * @param currentY the current Y coordinate to check
 * @return 1 if there is a collision, 0 otherwise
 */
int	ft_check_collision_x(t_data *map, double newX, double currentY)
{
	int	x;
	int	y;

	x = (int)newX;
	y = (int)currentY;
	if (map->map2d[x][y] == '1' || map->map2d[x][y] == '2')
		return (1);
	return (0);
}

/**
 * Check if there is a collision at the Y coordinate in the map
 * 
 * @param map The game map
 * @param newY The new Y coordinate to check
 * @param currentX the current Y coordinate
 * @return 1 if there is a collision, 0 otherwise
 */
int	ft_check_collision_y(t_data *map, double currentX, double newY)
{
	int	x;
	int	y;

	x = (int) currentX;
	y = (int) newY;
	if (map->map2d[x][y] == '1' || map->map2d[x][y] == '2')
		return (1);
	return (0);
}
