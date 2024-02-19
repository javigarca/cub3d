/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:07:27 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 16:09:29 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

void	ft_parse_map_lines(char **map2d, char *filename)
{
	char	*line;
	int		fd;
	char	*lineclear;
	int		count;

	count = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
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
