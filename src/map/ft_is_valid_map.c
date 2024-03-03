/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:06:34 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/03 12:07:22 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	ft_check_lines(const char *filename, int nlines);
static int	ft_n_dir(const char *line, char caracter);
static int	ft_check_lines_text(const char *filename, int nlines);
static int	ft_check_black_in_map(const char *filename, int nlines);

/**
 * Validates if the map in the file is valid.
 * 
 * @param filename The name of the file containing the map.
 * @return TRUE if the map is valid, FALSE otherwise.
 */
int	ft_is_valid_map(const char *filename)
{
	int	nlines;

	nlines = ft_count_files(filename);
	if (nlines < 9)
		return (ft_show_error("Less than 9 lines in file"));
	if (ft_check_lines_text(filename, nlines) == FALSE)
		return (FALSE);
	if (ft_check_black_in_map(filename, nlines) == FALSE)
		return (FALSE);
	if (ft_check_lines(filename, nlines) == FALSE)
		return (FALSE);
	return (TRUE);
}

/**
 * Validates if the lines in the file contain valid characters.
 * 
 * @param filename The name of the file to check.
 * @param nlines The total number of lines in the file.
 * @return FALSE if any line contains invalid characters,
 * 		   TRUE otherwise.
 */
static int	ft_check_lines_text(const char *filename, int nlines)
{
	char	*line;
	int		fd;
	int		pos;

	fd = open(filename, O_RDONLY);
	pos = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_line_all_spaces(line) && \
			ft_is_valid_line(pos++, line, nlines) == FALSE)
		{
			close(fd);
			free(line);
			return (FALSE);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (TRUE);
}

/**
 * Validates if there are any blank lines in the map section of the file.
 * 
 * @param filename The name of the file to check.
 * @param nlines The total number of lines in the file.
 * @return FALSE if a blank line is found in the map section,
 * 		   TRUE otherwise.
 */
static int	ft_check_black_in_map(const char *filename, int nlines)
{
	char	*line;
	int		fd;
	int		pos;

	fd = open(filename, O_RDONLY);
	pos = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_line_all_spaces(line) && !ft_is_valid_line(pos++, line, nlines))
			return (FALSE);
		if (pos > 7 && ft_line_all_spaces(line))
		{
			close(fd);
			free(line);
			return (ft_show_error("Blank line in map section."));
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (TRUE);
}

/**
 * Checks the lines in the map section of the file for valid content.
 * 
 * @param filename The name of the file to check.
 * @param nlines The total number of lines in the file.
 * @return FALSE if an invalid line is found, TRUE otherwise.
 */
static int	ft_check_lines(const char *filename, int nlines)
{
	char	*line;
	int		fd;
	int		pos;
	int		count;

	fd = open(filename, O_RDONLY);
	pos = 1;
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		if (!ft_line_all_spaces(line) && !ft_is_valid_line(pos++, line, nlines))
			return (FALSE);
		if (pos > 7)
		{
			count += ft_n_dir(line, 'N') + ft_n_dir(line, 'S');
			count += ft_n_dir(line, 'E') + ft_n_dir(line, 'W');
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (count > 1)
		return (ft_show_error("Too many spawn points."));
	return (TRUE);
}

/**
 * Counts the occurrences of a specific character in a string.
 * 
 * @param line The string to search for the character.
 * @param character The character to count occurrences of.
 * @return The number of occurrences of the character in the string.
 */
static int	ft_n_dir(const char *line, char character)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (line[i] != '\0')
	{
		if (line[i++] == character)
		{
			counter++;
		}
	}
	return (counter);
}
