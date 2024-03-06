/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_dda.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:03:29 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/06 01:25:47 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	ft_ray_calculate_sidedist(t_raysdt *ray, t_gamedata *gdata);
static void	ft_ray_calculate_walldist(t_raysdt *ray, t_gamedata *gdata);
static void	ft_ray_calculate_stripe(t_raysdt *ray, t_gamedata *gdata);
static void	ft_ray_calculate_wall_x(t_raysdt *ray, t_gamedata *gdata);

void	ft_calculate_dda(t_raysdt *ray, t_gamedata *gdata)
{
	ft_ray_calculate_sidedist(ray, gdata);
	ft_ray_calculate_walldist(ray, gdata);
	ft_ray_calculate_stripe(ray, gdata);
	ft_ray_calculate_wall_x(ray, gdata);
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
	while (!ray->wallhit)
	{
		ft_update_sidedist_and_map(ray);
		ray->wallhit = ft_is_wall_hit(gdata, ray);
		if (ray->wallhit)
			ft_calculate_walldist_and_height(ray, gdata);
	}
}

static void	ft_ray_calculate_stripe(t_raysdt *ray, t_gamedata *gdata)
{
	ray->strip_start = -ray->wallheight / 2 + H_RESOL / 2 + gdata->player.pitch;
	ray->strip_end = +ray->wallheight / 2 + H_RESOL / 2 + gdata->player.pitch;
	if (ray->strip_start < 0)
		ray->strip_start = 0;
	if (ray->strip_end >= H_RESOL)
		ray->strip_end = H_RESOL - 1;
}

static void	ft_ray_calculate_wall_x(t_raysdt *ray, t_gamedata *gdata)
{
	if (ray->side == 0)
		ray->wall_x = gdata->player.pos.y + ray->walldist * ray->dir.y;
	else
		ray->wall_x = gdata->player.pos.x + ray->walldist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
}
