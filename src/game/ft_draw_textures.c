/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:16:32 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/02 20:24:36 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_ray_calculate_texture(t_raysdt *ray, t_gamedata *gdata);
int	ft_get_texture_dimension(t_gamedata data, int direction, int type);
int	ft_get_texture_dimension(t_gamedata data, int direction, int type);
void	ft_light_my_pixel_n(t_gamedata *gdata, int x, int y, int color);
int	ft_get_wall_direction(t_raysdt *ray);
void	ft_draw_ray_wall_texture(t_gamedata *gdata, t_raysdt *ray);


void	ft_draw_textures(t_raysdt *ray, t_gamedata *data)
{
	ft_ray_calculate_texture(ray, data);
	ft_draw_ray_wall_texture(data, ray);
}


/*
int	ft_get_texture_dimension(t_gamedata data, int direction, int type)
{
	if (type == 0)
		return (data.sizee_x[direction]);
	return (data.sizee_y[direction]);
}*/


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

int	ft_get_wall_direction(t_raysdt *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir.x < 0)
			return (WEST);
		else
			return (EAST);
	}
	else
	{
		if (ray->dir.y > 0)
			return (SOUTH);
		return (NORTH);
	}
}

void	ft_draw_ray_wall_texture(t_gamedata *gdata, t_raysdt *ray)
{
	int	y;
	int	color;
	int	tex_width;
	int	wall;

	wall = ft_get_wall_direction(ray);
	tex_width = gdata->sizee_x[wall];
	y = ray->stripStart;
	while (y < ray->stripEnd)
	{
		ray->texY = (int)ray->texpos & (tex_width - 1);
		ray->texpos += ray->texture_step;
		color = gdata->textures[wall][tex_width * ray->texY + ray->texX];
		if (ft_get_wall_direction(ray) == NORTH)
			color = (color >> 1) & 8355711;
		if (ft_get_wall_direction(ray) == EAST)
			color = (color >> 1) & 8355711;
		ft_light_my_pixel_n(gdata, ray->pix, y, color);
		y++;
	}
}

void	ft_ray_calculate_texture(t_raysdt *ray, t_gamedata *gdata)
{
	int	tex_width;
	int	tex_height;
	int	wall;

	wall = ft_get_wall_direction(ray);
	tex_height =  gdata->sizee_y[wall];
	tex_width = gdata->sizee_x[wall];
	ray->texX = (int)(ray->wallX * (double)tex_width);
	if (ray->side == 0 && ray->dir.x > 0)
		ray->texX = tex_width - ray->texX - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		ray->texX = tex_width - ray->texX - 1;
	ray->texture_step = 1.0 * tex_height / ray->wallheight;
	ray->texpos = (ray->stripStart - gdata->player.pitch - \
			gdata->img_size.y / 2 + ray->wallheight / 2) * ray->texture_step;
}
