/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:50:58 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/02 10:55:43 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_free_gamedata(t_gamedata *data);
void	ft_free_data_map(t_data *data);

void	ft_exit_game(t_gamedata *data, char *output)
{
	if (data->win && data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		//mlx_destroy_display(data->mlx);
		//mlx_loop_end(data->mlx);
		free(data->mlx);
	}
	ft_free_gamedata(data);
	printf("%s\n", output);
	system("leaks cub3d");
}

void	ft_free_gamedata(t_gamedata *data)
{
	free(data->textures[0]);
	free(data->textures[1]);
	free(data->textures[2]);
	free(data->textures[3]);
	free(data->textures);
	ft_free_data_map(data->map);
	//free(data->ray);
	exit(0);
}

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
