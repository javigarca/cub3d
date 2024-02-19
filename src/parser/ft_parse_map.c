/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:50:26 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 14:15:19 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

char *ft_parse_map_texture(char **texture, char *filename, char *direction)
{


	*texture = ft_strdup("fkjdf");
	printf("%s, %s", filename, direction);

	return NULL;
}

t_data *ft_parse_map(char *filename)
{
	 t_data *data;
	(void)filename;
	data = ft_calloc(1, sizeof(t_data));
	data->map2d = ft_calloc(10, sizeof(char *)); // init the map
	data->map2d[0] = strdup("111111111111111111111111"); //fill the map
	data->map2d[1] = strdup("1000000000000000000100001");
	data->map2d[2] = strdup("1001000000000N00001100001");
	data->map2d[3] = strdup("1010000000000000001111001");
	data->map2d[4] = strdup("1010000000000000001000001");
	data->map2d[5] = strdup("1111000000100000001000001");
	data->map2d[6] = strdup("1001000010000000001000001");
	data->map2d[7] = strdup("1001000011110000001000001");
	data->map2d[8] = strdup("1111111110011111111111111");
	data->map2d[9] = NULL;

	data->c_celing.r = 250;
	data->c_celing.g = 0;
	data->c_celing.b = 127;

	data->c_floor.r = 250;
	data->c_floor.g = 0;
	data->c_floor.b = 127;

	data->p_x = 100;
	data->p_x = 200;

	data->w_map = 1920;
	data->h_map = 1080;

	data->t_no.texture_path = ft_strdup("textures/barrel.xpm");
	data->t_so.texture_path = ft_strdup("textures/barrel.xpm");
	data->t_we.texture_path = ft_strdup("textures/barrel.xpm");
	//data->t_ea.texture_path = ft_strdup("textures/barrel.xpm");
	ft_parse_map_texture(&data->t_ea.texture_path,filename,"NO");

	printf("\n tenemos %s \n", data->t_ea.texture_path);
	return (data);
}
