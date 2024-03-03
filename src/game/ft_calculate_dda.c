/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_dda.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:03:29 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/02 20:15:16 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

#define FACTOR .66

static void	ft_ray_calculate_sidedist(t_raysdt *ray, t_gamedata *gdata);
static void	ft_ray_calculate_walldist(t_raysdt *ray, t_gamedata *gdata);
static void	ft_ray_calculate_stripe(t_raysdt *ray, t_gamedata *gdata);
static void	ft_ray_calculate_wallx(t_raysdt *ray, t_gamedata *gdata);

void	ft_calculate_dda(t_raysdt *ray, t_gamedata *gdata)
{
	ft_ray_calculate_sidedist(ray, gdata);
	ft_ray_calculate_walldist(ray, gdata);
	ft_ray_calculate_stripe(ray, gdata);
	ft_ray_calculate_wallx(ray, gdata);
}

static void	ft_ray_calculate_sidedist(t_raysdt *ray, t_gamedata *gdata)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (gdata->player.pos.x - ray->map.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map.x + 1.0 - gdata->player.pos.x) * \
							ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (gdata->player.pos.y - ray->map.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map.y + 1.0 - gdata->player.pos.y) * \
							ray->delta.y;
	}
}

static void	ft_ray_calculate_walldist(t_raysdt *ray, t_gamedata *gdata)
{
	while (ray->wallhit == 0)
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
		if (gdata->map->map2d[ray->map.x][ray->map.y] == '1' || gdata->map->map2d[ray->map.x][ray->map.y] == '2')
			ray->wallhit = 1;
		if (ray->side == 0)
			ray->walldist = ray->sidedist.x - ray->delta.x;
		else
			ray->walldist = ray->sidedist.y - ray->delta.y;
	}
	if (ray->walldist == 0)
		ray->wallheight = FACTOR * gdata->img_size.y ;
	else
		ray->wallheight = FACTOR * gdata->img_size.y / ray->walldist;
}

static void	ft_ray_calculate_stripe(t_raysdt *ray, t_gamedata *gdata)
{
	ray->stripStart = -ray->wallheight / 2 + H_RESOL / 2 + gdata->player.pitch;
	ray->stripEnd = +ray->wallheight / 2 + H_RESOL / 2 + gdata->player.pitch;
	if (ray->stripStart < 0)
		ray->stripStart = 0;
	if (ray->stripEnd >= H_RESOL)
		ray->stripEnd = H_RESOL - 1;
}

static void	ft_ray_calculate_wallx(t_raysdt *ray, t_gamedata *gdata)
{
	if (ray->side == 0)
		ray->wallX = gdata->player.pos.y + ray->walldist * ray->dir.y;
	else
		ray->wallX = gdata->player.pos.x + ray->walldist * ray->dir.x;
	ray->wallX -= floor(ray->wallX);
}
