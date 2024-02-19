/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:50:26 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 15:48:07 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

char *ft_parse_map_color(t_color *color, char *filename, char *type)
{
	char **elements;
	char *line;
	int fd;
	char **colors;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line !=NULL)
	{
		elements = ft_split(line, ' ');
		if (ft_strncmp(elements[0], type, 1) == 0)
		{
			colors = ft_split(elements[1],',');
			color->r = ft_atoi(colors[0]);
			color->g = ft_atoi(colors[1]);
			color->b = ft_atoi(colors[2]);
			break;
		}
		line = get_next_line(fd);
	}
	free(elements);
	free(colors);
	free(line);
	return NULL;
}

char *ft_parse_map_texture(char **texture, char *filename, char *direction)
{
	char **elements;
	char *line;
	int fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line !=NULL)
	{
		elements = ft_split(line, ' ');
		if (ft_strncmp(elements[0], direction,2) == 0)
		{
			*texture = ft_strdup(elements[1]);
			break;
		}
		line = get_next_line(fd);
	}
	free(elements);
	free(line);
	return NULL;
}

int ft_count_map_lines(char *filename)
{
	char *line;
	int fd;
	int count;
	char *lineclear;

	count = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line !=NULL)
	{
		lineclear = ft_strtrim(line, " ");
		if (lineclear[0] == '1' || lineclear[0] == '0')
			count ++;
		line = get_next_line(fd);
	}
	free(lineclear);
	free(line);
	return (count);
}

void ft_parse_map_lines(char **map2d, char *filename)
{
	char *line;
	int fd;
	char *lineclear;
	int count;
	
	count = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line !=NULL)
	{
		lineclear = ft_strtrim(line, " ");
		if (lineclear[0] == '1' || lineclear[0] == '0')
		{
			map2d[count] = ft_strdup(lineclear);
			count ++;
		}
			
		line = get_next_line(fd);
	}
	free(lineclear);
	free(line);

}
t_data *ft_parse_map(char *filename)
{
	t_data *data;
	
	data = ft_calloc(1, sizeof(t_data));
	data->map2d = ft_calloc(ft_count_map_lines(filename) + 1, sizeof(char *)); // init the map
	ft_parse_map_lines(data->map2d, filename);
	ft_parse_map_texture(&data->t_no.texture_path,filename,"NO");
	ft_parse_map_texture(&data->t_so.texture_path,filename,"SO");
	ft_parse_map_texture(&data->t_we.texture_path,filename,"WE");
	ft_parse_map_texture(&data->t_ea.texture_path,filename,"EA");
	ft_parse_map_color(&data->c_floor, filename, "F");
	ft_parse_map_color(&data->c_celing, filename, "C");
	data->p_x = 100;
	data->p_x = 200;
	data->w_map = 1920;
	data->h_map = 1080;
	return (data);
}
