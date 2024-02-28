/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:24:41 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/28 13:42:35 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#define TEXWIDTH 64
#define FACTOR 1
static void	ft_ray_init(t_raysdt *ray, t_gamedata *gdata);
//static void ft_print_ray_info(t_raysdt *ray, t_gamedata *gdata, int type);

void	ft_ray_calculate_sidedist(t_raysdt *ray, t_gamedata *gdata)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (gdata->player.pos.x - ray->map.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map.x + 1.0 - gdata->player.pos.x) * ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (gdata->player.pos.y - ray->map.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map.y + 1.0 - gdata->player.pos.y) * ray->delta.y;
	}
}
void ft_ray_calculate_walldist(t_raysdt *ray, t_gamedata *gdata)
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
		if (gdata->map->map2d[ray->map.x][ray->map.y] == '1')
			ray->wallhit = 1;
		if (ray->side == 0)
			ray->walldist = ray->sidedist.x - ray->delta.x;
		else
			ray->walldist = ray->sidedist.y - ray->delta.y;
	}
	if (ray->walldist == 0)
		ray->wallheight = FACTOR* gdata->img_size.y ;
	else
		ray->wallheight = FACTOR* gdata->img_size.y / ray->walldist;
}

void ft_ray_calculate_stripe(t_raysdt *ray)
{
	ray->stripStart = - ray->wallheight / 2 + H_RESOL / 2 + ray->pitch;
	ray->stripEnd = + ray->wallheight / 2 + H_RESOL / 2 + ray->pitch;
	if (ray->stripStart < 0)
		ray->stripStart = 0;
	if (ray->stripEnd >= H_RESOL)
		ray->stripEnd = H_RESOL -	1;
}
void	ft_raycasting(t_gamedata *gdata)
{
	t_raysdt	*ray;
	int y;

	ray = ft_calloc(1, sizeof (t_raysdt));
	if (!ray)
		printf("Error: failed to allocate memory for raycasting");
	
	//ray->wallhit = 0;
	while (ray->pix < gdata->img_size.x)
	{
		ft_ray_init(ray, gdata);
		ft_ray_calculate_sidedist(ray, gdata);
		ft_ray_calculate_walldist(ray, gdata);
		ft_ray_calculate_stripe(ray);
		printf("\n pix: %d wallheight: %f", ray->pix,ray->wallheight);
		printf("\tstripe Start:%d End:%d", ray->stripStart, ray->stripEnd);
		// EMPEZANDO TEXTURAS
		// 1. calcular la posicion de la pared
		if (ray->side == 0)
			ray->wallX = gdata->player.pos.y + ray->walldist * ray->dir.y;
		else
			ray->wallX = gdata->player.pos.x + ray->walldist * ray->dir.x;
		ray->wallX -= floor(ray->wallX);

		printf("\twallX: %f	", ray->wallX);
		// 2. calcular la posicion de la textura
		ray->texX = (int)(ray->wallX * (double)TEXWIDTH);
		if (ray->side == 0 && ray->dir.x > 0)
			ray->texX = TEXWIDTH - ray->texX - 1;
		if (ray->side == 1 && ray->dir.y < 0)
			ray->texX = TEXWIDTH - ray->texX - 1;
		//printf("texX: %d\n", ray->texX);
		// 3. calcular la posicion de la textura en la pared
		
		//printf("step: %f\n", step);
		// 4. pintar la textura en la pared
		int pitch = 0;
		int drawStart = -ray->wallheight/2 + gdata->img_size.y/2 + pitch;
		if (drawStart == 0)
			drawStart = 0;
		int drawEnd = ray->wallheight/2 + gdata->img_size.y/2 + pitch;
		if (drawEnd > gdata->img_size.y)
			drawEnd = gdata->img_size.y -1;

		double step = 1.0 * TEXWIDTH / ray->wallheight;
		ray->texpos = (drawStart - pitch - gdata->img_size.y/2 + ray->wallheight / 2)* step;
		
		int color;

		y = drawStart;
		while (y < drawEnd)
		{
			ray->texY = (int)ray->texpos & (64 -1); //cambiar 64 por tamaño textura 
			ray->texpos += step;
			color = gdata->textures[1][64 * ray->texY + ray->texX];
			y++;
		}
		
		ft_draw_ray_wall(gdata, ray, color);
		ray->pix++;
	}
}

static void	ft_ray_init(t_raysdt *ray, t_gamedata *gdata)
{
	ray->camerax = (2 * ray->pix) / (double)gdata->win_size.x - 1;
	//cameraX is the x-coordinate on the camera plane that the current x-coordinate of the screen represents, done this way so that the right side of the screen will get coordinate 1, the center of the screen gets coordinate 0, and the left side of the screen gets coordinate -1. Out of this, the direction of the ray can be calculated as was explained earlier: as the sum of the direction vector, and a part of the plane vector. This has to be done both for the x and y coordinate of the vector (since adding two vectors is adding their x-coordinates, and adding their y-coordinates).
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
	ray->pitch = 0; // se puede cambiar a 100
	
}
/*
static void ft_print_ray_info(t_raysdt *ray, t_gamedata *gdata, int type)
{
	if (type == 0)
	{
		printf("\nray pix %d", ray->pix);
		printf("\nplayer plane x %f", gdata->player.plane.x);
		printf("\nplayer plane y %f", gdata->player.plane.y);

		printf("\ncamerax: %f\n", ray->camerax);
		printf("dir.x: %f, dir.y: %f\n", ray->dir.x, ray->dir.y);
		printf("map.x: %d, map.y: %d\n", ray->map.x, ray->map.y);
		printf("delta.x: %f, delta.y: %f\n", ray->delta.x, ray->delta.y);
		printf("wallhit: %d\n", ray->wallhit);
	}
	if (type == 1)
	{
		printf("map.x: %d, map.y: %d", ray->map.x, ray->map.y);
		printf(" X= %d", ray->pix);
	}
	
}*/