/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:50:26 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/21 15:02:43 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

t_data	*ft_check_map_data(t_data *data)
{
	if (data->t_no.texture_path == NULL || data->t_we.texture_path == NULL || \
		data->t_so.texture_path == NULL || data->t_ea.texture_path == NULL)
	{
		ft_free_data(data);
		return (ft_show_parse_error("Missing texture direction"));
	}
	if (data->c_celing.r == -1 || data->c_celing.g == -1 || \
		data->c_celing.b == -1)
	{
		ft_free_data(data);
		return (ft_show_parse_error("Missing/Wrong ceiling R.G.B. color"));
	}
	if (data->c_floor.r == -1 || data->c_floor.g == -1 || \
		data->c_floor.b == -1)
	{
		ft_free_data(data);
		return (ft_show_parse_error("Missing/Wrong floor R.G.B. color"));
	}
	if (data->p_x == -1 || data->p_y == -1)
	{
		ft_free_data(data);
		return (ft_show_parse_error("Missing spawn point."));
	}
	return (data);
}

/**
 * Initializes and sets up the `t_data` data structure to store map information.
 *
 * This function allocates memory for a new `t_data` structure 
 * and initializes it with default values.
 * Paths to textures and floor and ceiling colors are set to invalid values (-1),
 * indicating that they have not yet been configured.
 * The player's position is also initialized to invalid values (-1),
 * indicating that it has not yet been found on the map.
 *
 * @param filename The name of the map file to be processed.
 * @return A pointer to the initialized `t_data` structure.
 */
t_data	*ft_init_data(char *filename)
{
	t_data	*data;
	int		i;

	data = ft_calloc(1, sizeof(t_data));
	data->map2d = ft_calloc(ft_count_map_lines(filename) + 1, sizeof(char *));
	i = 0;
	while (i < ft_count_map_lines(filename) + 1)
		data->map2d[i++] = NULL;
	data->c_celing.r = -1;
	data->c_celing.g = -1;
	data->c_celing.b = -1;
	data->c_floor.r = -1;
	data->c_floor.g = -1;
	data->c_floor.b = -1;
	data->p_x = -1;
	data->p_y = -1;
	return (data);
}

/**
 * Parses a map file and populates a `t_data` structure with its contents.
 *
 * @param filename The path to the map file.
 *
 * @return A pointer to a newly allocated `t_data` structure containing the
 * parsed map data, or NULL on failure.
 *
 * This function parses a map file specified by `filename` and populates a
 * `t_data` structure with the extracted information. The structure contains
 * the following members:
 *
 */
t_data	*ft_parse_map(char *filename)
{
	t_data	*data;

	data = ft_init_data(filename);
	ft_parse_map_lines(data->map2d, filename);
	ft_parse_map_texture(&data->t_no.texture_path, filename, "NO");
	ft_parse_map_texture(&data->t_so.texture_path, filename, "SO");
	ft_parse_map_texture(&data->t_we.texture_path, filename, "WE");
	ft_parse_map_texture(&data->t_ea.texture_path, filename, "EA");
	ft_parse_map_color(&data->c_floor, filename, "F");
	ft_parse_map_color(&data->c_celing, filename, "C");
	ft_parse_map_player(&data->p_x, &data->p_y, filename);
	data->w_map = W_RESOL;
	data->h_map = H_RESOL;
	return (ft_check_map_data(data));
}
