/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:16:32 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/03 10:56:56 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_ray_calculate_texture(t_raysdt *ray, t_gamedata *gdata);
int		ft_get_texture_dimension(t_gamedata data, int direction, int type);
int		ft_get_texture_dimension(t_gamedata data, int direction, int type);
void	ft_light_my_pixel_n(t_gamedata *gdata, int x, int y, int color);
int	ft_get_wall_direction(t_gamedata *gdata, t_raysdt *ray);
void	ft_draw_ray_wall_texture(t_gamedata *gdata, t_raysdt *ray);

/**
 * Draw the textures on the screen for a given ray.
 * 
 * @param ray Pointer to the ray structure
 * @param data Pointer to the game data structure
 */
void	ft_draw_textures(t_raysdt *ray, t_gamedata *data)
{
	ft_ray_calculate_texture(ray, data);
	ft_draw_ray_wall_texture(data, ray);
}

/**
 * Set the color of a pixel at a specific position on the screen.
 * 
 * @param gdata Pointer to the game data structure
 * @param x The x-coordinate of the pixel
 * @param y The y-coordinate of the pixel
 * @param color The color value to set the pixel to
 */
void	ft_light_my_pixel_n(t_gamedata *gdata, int x, int y, int color)
{
	int	lpixel;
	int	width;
	int	height;

	width = gdata->img_size.x;
	height = gdata->img_size.y;
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		lpixel = (x * gdata->pixel_b / 8) + (y * gdata->lines_b);
		gdata->imgadd[lpixel] = color;
		gdata->imgadd[++lpixel] = color >> 8;
		gdata->imgadd[++lpixel] = color >> 16;
	}
}

int	ft_get_wall_direction(t_gamedata *gdata, t_raysdt *ray)
{
	if (gdata->map->map2d[ray->map.x][ray->map.y] == '2')
		return (DOORC);
	if (ray->side == 0)
	{
		if (ray->dir.x < 0)
			return (NORTH);
		else
			return (SOUTH);
	}
	else
	{
		if (ray->dir.y > 0)
			return (EAST);
		return (WEST);
	}
}

/**
 * Draw the texture of a ray hitting a wall on the screen.
 * 
 * @param gdata Pointer to the game data structure
 * @param ray Pointer to the ray structure
 */
void	ft_draw_ray_wall_texture(t_gamedata *gdata, t_raysdt *ray)
{
	int	y;
	int	color;
	int	tex_width;
	int	wall;

	wall = ft_get_wall_direction(gdata, ray);
	tex_width = gdata->sizee_x[wall];
	y = ray->strip_start;
	while (y < ray->strip_end)
	{
		ray->tex_y = (int)ray->texpos & (tex_width - 1);
		ray->texpos += ray->texture_step;
		color = gdata->textures[wall][tex_width * ray->tex_y + ray->tex_x];
		if (ft_get_wall_direction(gdata, ray) == NORTH)
			color = (color >> 1) & 8355711;
		if (ft_get_wall_direction(gdata, ray) == EAST)
			color = (color >> 1) & 8355711;
		ft_light_my_pixel_n(gdata, ray->pix, y, color);
		y++;
	}
}

/**
 * Calculate the texture coordinates for drawing a ray hitting a wall.
 * 
 * @param ray Pointer to the ray structure
 * @param gdata Pointer to the game data structure
 */
void	ft_ray_calculate_texture(t_raysdt *ray, t_gamedata *gdata)
{
	int	tex_width;
	int	tex_height;
	int	wall;

	wall = ft_get_wall_direction(gdata, ray);
	tex_height =  gdata->sizee_y[wall];
	tex_width = gdata->sizee_x[wall];
	ray->tex_x = (int)(ray->wall_x * (double)tex_width);
	if (ray->side == 0 && ray->dir.x > 0)
		ray->tex_x = tex_width - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		ray->tex_x = tex_width - ray->tex_x - 1;
	ray->texture_step = 1.0 * tex_height / ray->wallheight;
	ray->texpos = (ray->strip_start - gdata->player.pitch - \
			gdata->img_size.y / 2 + ray->wallheight / 2) * ray->texture_step;
}
