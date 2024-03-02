/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:10:51 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/02 11:28:55 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	*ft_xpm_to_array(t_gamedata *data, int type);
static void	ft_init_texture_img(t_gamedata *data, t_img *image, int type);
void		ft_clear_img(t_img *image);

/**
 * Load textures into the game data.
 * 
 * @param gdata - The game data structure
 */
void	ft_load_textures(t_gamedata *gdata)
{
	gdata->textures = malloc(sizeof(int *) * 5);
	if (!gdata->textures) //hay que arreglar uninitialised values
		ft_exit_game(gdata,"Malloc failed. exit");
	gdata->textures[NORTH] = ft_xpm_to_array(gdata, NORTH);
	gdata->textures[SOUTH] = ft_xpm_to_array(gdata, SOUTH);
	gdata->textures[EAST] = ft_xpm_to_array(gdata, EAST);
	gdata->textures[WEST] = ft_xpm_to_array(gdata, WEST);
}

/**
 * Convert XPM image data to an array of integers.
 * 
 * @param data - The game data structure
 * @param type - The type of texture (NORTH, SOUTH, EAST, WEST)
 * @return int* - The array of integers representing the texture
 */
static int	*ft_xpm_to_array(t_gamedata *data, int type)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	ft_init_texture_img(data, &tmp, type);
	buffer = ft_calloc(1, sizeof * buffer * data->size_x * data->size_y);
	if (!buffer)//hay que arreglar uninitialised values
		ft_exit_game(data,"Malloc failed. exit");
	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			buffer[y * data->size_y + x] = tmp.addr[y * data->size_y + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

/**
 * Initialize the texture image based on the type provided.
 * 
 * @param data - The game data structure
 * @param image - The image structure to initialize
 * @param type - The type of texture (NORTH, SOUTH, EAST, WEST)
 */
static void	ft_init_texture_img(t_gamedata *data, t_img *image, int type)
{
	char	*texture_path;

	
	ft_clear_img(image);
	if (type == NORTH)
	{
		texture_path = ft_strdup(data->map->t_no.texture_path);
		image->img = mlx_xpm_file_to_image(data->mlx, texture_path, \
										&data->N_size_x, &data->N_size_y);
		data->size_x = data->N_size_x;
		data->size_y = data->N_size_y;
		data->sizee_x[NORTH] = data->N_size_x;
		data->sizee_y[NORTH] = data->N_size_y;
	}
	else if (type == SOUTH)
	{
		texture_path = ft_strdup(data->map->t_so.texture_path);
		image->img = mlx_xpm_file_to_image(data->mlx, texture_path, \
										&data->S_size_x, &data->S_size_y);
		data->size_x = data->S_size_x;
		data->size_y = data->S_size_y;
		data->sizee_x[SOUTH] = data->S_size_x;
		data->sizee_y[SOUTH] = data->S_size_y;
	}
		
	else if (type == EAST)
	{
		texture_path = ft_strdup(data->map->t_ea.texture_path);
		image->img = mlx_xpm_file_to_image(data->mlx, texture_path, \
										&data->E_size_x, &data->E_size_y);
		data->size_x = data->E_size_x;
		data->size_y = data->E_size_y;
		data->sizee_x[EAST] = data->E_size_x;
		data->sizee_y[EAST] = data->E_size_y;
	}
	else
	{
		texture_path = ft_strdup(data->map->t_we.texture_path);
		image->img = mlx_xpm_file_to_image(data->mlx, texture_path, \
										&data->W_size_x, &data->W_size_y);
		data->size_x = data->W_size_x;
		data->size_y = data->W_size_y;
		data->sizee_x[WEST] = data->W_size_x;
		data->sizee_y[WEST] = data->W_size_y;
	}
		
	
	
	if (image->img == NULL)
		printf("ERROR reading xmp");
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits, \
											&image->size_line, &image->endian);
	free(texture_path);


	printf("\n type= %d size= %d %d\n", type, data->sizee_x[type], data->sizee_y[type]);

	
	return ;
}

/**
 * Set all image properties to default values.
 * 
 * @param image - The image structure to clear
 */
void	ft_clear_img(t_img *image)
{
	image->img = NULL;
	image->addr = NULL;
	image->pixel_bits = 0;
	image->size_line = 0;
	image->endian = 0;
}
