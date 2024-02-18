/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:06:34 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/18 11:36:50 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_check_files(const char *filename, int nlines);

/**
 * Checks if a given file contains a valid map representation.
 *
 * @param filename  The name of the file to check.
 * @return          TRUE if the file is a valid map, FALSE otherwise.
 *
 *  - Validates that the file has at least 9 lines.
 *  - Calls `ft_check_files` to perform more detailed checks.
 *  - Returns FALSE and displays an error message if the file is invalid.
 */
int	ft_is_valid_map(const char *filename)
{
	int	nlines;

	nlines = ft_count_files(filename);
	if (nlines < 9)
		return (ft_show_error("Less than 9 lines in file"));
	if (ft_check_files(filename, nlines) == FALSE)
		return (FALSE);
	return (TRUE);
}

/**
 * Checks the individual lines of a file to ensure they meet map requirements.
 *
 * @param filename  The name of the file to check.
 * @param nlines    The number of lines in the file.
 * @return          TRUE if all lines are valid, FALSE otherwise.
 *
 *  - Opens the file in read-only mode.
 *  - Iterates through each line of the file:
 *      - Skips lines that only contain spaces.
 *      - Calls `ft_is_valid_line` to check if the line is valid.
 *      - Returns FALSE and closes the file if an invalid line is encountered.
 *  - Returns TRUE if all lines are valid.
 */
static int	ft_check_files(const char *filename, int nlines)
{
	char	*line;
	int		fd;
	int		pos;

	fd = open(filename, O_RDONLY);
	pos = 1;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_line_all_spaces(line) == FALSE)
		{
			if (ft_is_valid_line(pos++, line, nlines) == FALSE)
			{
				close(fd);
				free(line);
				return (FALSE);
			}
		}
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (TRUE);
}
