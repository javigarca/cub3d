/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:50:26 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/20 12:05:52 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

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

	data = ft_calloc(1, sizeof(t_data));
	data->map2d = ft_calloc(ft_count_map_lines(filename) + 1, sizeof(char *));
	ft_parse_map_lines(data->map2d, filename);
	ft_parse_map_texture(&data->t_no.texture_path, filename, "NO");
	ft_parse_map_texture(&data->t_so.texture_path, filename, "SO");
	ft_parse_map_texture(&data->t_we.texture_path, filename, "WE");
	ft_parse_map_texture(&data->t_ea.texture_path, filename, "EA");
	ft_parse_map_color(&data->c_floor, filename, "F");
	ft_parse_map_color(&data->c_celing, filename, "C");
	ft_parse_map_player(&data->p_x, &data->p_y, filename);
	data->w_map = 1920;
	data->h_map = 1080;
	return (data);
}
