/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:07:27 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/05 16:21:32 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

static void	ft_replace_space_zeros(char *str);

/**
 * Parses lines from a map file and populates a 2D character array.
 *
 * @param map2d A 2D character array to store the parsed map lines.
 * @param filename The path to the map file.
 *
 * This function reads lines from the map file specified by `filename` and
 * stores them in the provided `map2d` array. Each line in the map file
 * represents a row of the map layout.
 *
 */
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
		lineclear = ft_strdup(line);
		ft_replace_space_zeros(lineclear);
		if (lineclear[0] == '1' || lineclear[0] == '0' || lineclear[0] == '2')
		{
			map2d[count] = ft_strdup(lineclear);
			count ++;
		}
		free(line);
		free(lineclear);
		line = get_next_line(fd);
	}
}

/**
 * Replaces spaces with zeros in a string.
 *
 * @param str The string to modify.
 */
static void	ft_replace_space_zeros(char *str)
{
	int	length;
	int	i;

	i = 0;
	length = ft_strlen(str);
	while (i < length)
	{
		if (str[i] == ' ')
			str[i] = '0';
		i++;
	}
}
