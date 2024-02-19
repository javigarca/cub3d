/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:04:24 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 16:06:33 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

char	*ft_parse_map_texture(char **texture, char *filename, char *direction)
{
	char	**elements;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		elements = ft_split(line, ' ');
		if (ft_strncmp(elements[0], direction, 2) == 0)
		{
			*texture = ft_strdup(elements[1]);
			break ;
		}
		line = get_next_line(fd);
	}
	free(elements);
	free(line);
	return (NULL);
}
