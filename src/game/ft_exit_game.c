/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:50:58 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/06 12:23:56 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_free_gamedata(t_gamedata *data);
void	ft_free_data_map(t_data *data);

/**
 * Exit the game and free resources.
 * 
 * @param data Pointer to the game data structure.
 * @param output Message to display upon exit.
 * 	//mlx_destroy_display(data->mlx);
 *	//mlx_loop_end(data->mlx);
 */
void	ft_exit_game(t_gamedata *data, char *output)
{
	if (data->win && data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	printf("Exit: %s", output);
	ft_free_gamedata(data);
}

/**
 * Free the allocated memory for textures and the map data.
 * 
 * @param data Pointer to the game data structure.
 *	//free(data->ray);
 */
void	ft_free_gamedata(t_gamedata *data)
{
	free(data->textures[0]);
	free(data->textures[1]);
	free(data->textures[2]);
	free(data->textures[3]);
	free(data->textures[4]);
	free(data->textures[5]);
	free(data->textures);
	ft_free_data_map(data->map);
	exit(0);
}

/**
 * Free the memory allocated for the map data and texture paths.
 * 
 * @param data Pointer to the data structure containing the map 
 * 			   and texture paths.
 */
void	ft_free_data_map(t_data *data)
{
	int	i;

	if (!data)
		return ;
	if (data->map2d)
	{
		i = 0;
		while (data->map2d[i])
		{
			free(data->map2d[i]);
			i++;
		}
		free(data->map2d);
	}
	free(data->t_no.texture_path);
	free(data->t_so.texture_path);
	free(data->t_we.texture_path);
	free(data->t_ea.texture_path);
	free(data);
}
