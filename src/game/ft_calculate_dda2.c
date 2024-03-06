/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_dda2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 01:13:32 by javi              #+#    #+#             */
/*   Updated: 2024/03/06 01:18:58 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_update_sidedist_and_map(t_raysdt *ray)
{
	if (ray->sidedist.x < ray->sidedist.y)
	{
		ray->sidedist.x += ray->delta.x;
		ray->map.x += ray->step.x;
		ray->side = 0;
	}
	else
	{
		ray->sidedist.y += ray->delta.y;
		ray->map.y += ray->step.y;
		ray->side = 1;
	}
}

int	ft_is_wall_hit(t_gamedata *gdata, t_raysdt *ray)
{
	return (gdata->map->map2d[ray->map.x][ray->map.y] > 48 && \
			gdata->map->map2d[ray->map.x][ray->map.y] < 52);
}

void	ft_calculate_walldist_and_height(t_raysdt *ray, t_gamedata *gdata)
{
	if (ray->side == 0)
		ray->walldist = ray->sidedist.x - ray->delta.x;
	else
		ray->walldist = ray->sidedist.y - ray->delta.y;
	if (ray->walldist == 0)
		ray->wallheight = FACTOR * gdata->img_size.y;
	else
		ray->wallheight = FACTOR * gdata->img_size.y / ray->walldist;
}
