/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:58:12 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/02 11:01:37 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_clear_image(t_gamedata *gdata, int color_a, int color_b);
void	ft_light_rect(t_gamedata *gdata, t_coord begin, t_coord end, int color);
void	ft_light_my_pixel(t_gamedata *gdata, int x, int y, int color);

void	ft_start_draw(t_gamedata *gdata)
{
	//ft_clear_image(gdata, BKG_CLR_A, BKG_CLR_A); 
	ft_raycasting(gdata);
	//mlx_put_image_to_window(gdata->mlx, gdata->win, gdata->img, 0, 0);
}

/**
 * Clears the image by filling it with alternating colors specified 
 * by color_a and color_b.
 * 
 * @param gdata Pointer to the game data structure.
 * @param color_a Color value for pixels at odd y positions.
 * @param color_b Color value for pixels at even y positions.
 */
void	ft_clear_image(t_gamedata *gdata, int color_a, int color_b)
{
	int	x;
	int	y;

	x = 0;
	while (x < gdata->win_size.x)
	{
		y = 0;
		while (y < gdata->win_size.y)
		{
			if (y % 2)
				ft_light_my_pixel(gdata, x, y, color_a);
			else
				ft_light_my_pixel(gdata, x, y, color_b);
			++y;
		}
		++x;
	}
}

/**
 * Lights up a pixel at coordinates (x, y) with the specified color.
 * 
 * @param gdata Pointer to the game data structure.
 * @param x X-coordinate of the pixel.
 * @param y Y-coordinate of the pixel.
 * @param color Color value to set the pixel.
 */
void	ft_light_my_pixel(t_gamedata *gdata, int x, int y, int color)
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

/**
 * Lights up a rectangular area defined by the beginning 
 * and end coordinates with the specified color.
 * 
 * @param gdata Pointer to the game data structure.
 * @param begin Starting coordinates of the rectangle.
 * @param end Ending coordinates of the rectangle.
 * @param color Color value to fill the rectangle.
 */
void	ft_light_rect(t_gamedata *gdata, t_coord begin, t_coord end, int color)
{
	double	i;
	double	j;

	i = begin.x;
	while (i <= end.x)
	{
		j = begin.y;
		while (j <= end.y)
		{
			ft_light_my_pixel(gdata, i, j, color);
			j++;
		}
		i++;
	}
}

/**
 * Draws a wall segment represented by the ray with the specified color.
 * 
 * @param gdata Pointer to the game data structure.
 * @param ray Pointer to the ray data structure.
 * @param color Color value for the wall segment.
 */
void	ft_draw_ray_wall(t_gamedata *gdata, t_raysdt *ray, int color)
{
	int	i;

	if (ray->side == 1)
		color = color / 2;
	i = ray->stripStart;
	while (i <= ray->stripEnd)
	{
		ft_light_my_pixel(gdata, ray->pix, i, color);
		i++;
	}
}
