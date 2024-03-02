/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:24:41 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/02 20:18:21 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"



static void	ft_ray_init(t_raysdt *ray, t_gamedata *gdata);
void	ft_ray_calculate_texture(t_raysdt *ray, t_gamedata *gdata);
void	ft_draw_ray_wall_texture(t_gamedata *gdata, t_raysdt *ray);

void	ft_raycasting(t_gamedata *gdata)
{
	t_raysdt	*ray;

	ray = ft_calloc(1, sizeof (t_raysdt));
	if (!ray)
		printf("Error: failed to allocate memory for raycasting");
	ft_sky_floor_draw(gdata);
	while (ray->pix < gdata->img_size.x)
	{
		ft_ray_init(ray, gdata);
		ft_calculate_dda(ray, gdata);
		ft_draw_textures(ray, gdata);
		ray->pix++;
	}
	free(ray);
}

static void	ft_ray_init(t_raysdt *ray, t_gamedata *gdata)
{
	ray->camerax = (2 * ray->pix) / (double)gdata->win_size.x - 1;
	ray->dir.x = (gdata->player.dir.x + gdata->player.plane.x * ray->camerax);
	ray->dir.y = gdata->player.dir.y + gdata->player.plane.y * ray->camerax;
	ray->map.x = (int)gdata->player.pos.x;
	ray->map.y = (int)gdata->player.pos.y;
	if (ray->dir.x == 0)
		ray->delta.x = 1E30;
	else
		ray->delta.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta.y = 1E30;
	else
		ray->delta.y = fabs(1 / ray->dir.y);
	ray->wallX = 0;
	ray->texX = 0;
	ray->wallhit = 0;
	ray->stripStart = 0;
	ray->stripEnd = 0;
}
