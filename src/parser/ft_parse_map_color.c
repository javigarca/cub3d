/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:01:07 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 16:03:45 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

char	*ft_parse_map_color(t_color *color, char *filename, char *type)
{
	char	**elements;
	char	*line;
	int		fd;
	char	**colors;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		elements = ft_split(line, ' ');
		if (ft_strncmp(elements[0], type, 1) == 0)
		{
			colors = ft_split(elements[1], ',');
			color->r = ft_atoi(colors[0]);
			color->g = ft_atoi(colors[1]);
			color->b = ft_atoi(colors[2]);
			break ;
		}
		line = get_next_line(fd);
	}
	free(elements);
	free(colors);
	free(line);
	return (NULL);
}
