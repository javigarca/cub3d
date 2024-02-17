/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:06:34 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/18 00:02:42 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
int ft_is_color_line(const char *type, const char *line);
int	ft_is_valid_line(int position, const char *line, int n_lines);

int	ft_is_valid_map(const char *filename)
{
	char	*line;
	int		fd;
	int		pos;
	int		nlines;

	nlines = ft_count_files(filename);
	if (nlines < 9)
	{
		printf("Error. Menos de 9 lineas ");
		return (FALSE);
	}
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

int ft_is_color_line(const char *type, const char *line)
{
	(void)line;
	(void)type;
	return (TRUE);
}
int	ft_is_valid_texture_line(const char *direction, const char *line)
{
	(void)direction;
	char ** data;

	data = ft_split(line,' ');
	if (ft_2d_array_size(data) != 2)
	{
		printf(KRED"ERROR\n"KWHT"CUBE3D: To many arguments in line\n");
		free(data);
		return (FALSE);
	}
	if (ft_strncmp(data[0],direction,2) != 0 || ft_strlen(data[0])!=2)
	{
		printf(KRED"ERROR\n"KWHT"CUBE3D: Error in texture line\n");
		free(data);
		return (FALSE);	
	}
	printf("%s\n",ft_str_remove_newline(data[1]));
	if (ft_is_valid_filename(ft_str_remove_newline(data[1]))== FALSE)
	{
		printf(KRED"ERROR\n"KWHT"CUBE3D: Error in texture line\n");
		free(data);
		return (FALSE);	

	}
	free(data);
	return (TRUE);
}
int	ft_is_valid_line(int position, const char *line, int n_lines)
{
	if (position == 1 && ft_is_valid_texture_line("NO", line) == FALSE)
		return (FALSE);
	if (position == 2 && ft_is_valid_texture_line("SO", line) == FALSE)
		return (FALSE);
	if (position == 3 && ft_is_valid_texture_line("WE", line) == FALSE)
		return (FALSE);
	if (position == 4 && ft_is_valid_texture_line("EA", line) == FALSE)
		return (FALSE);
	if (position == 5 && ft_is_color_line("F", line) == FALSE)
		return (FALSE);
	if (position == 6 && ft_is_color_line("C", line) == FALSE)
		return (FALSE);
	(void)n_lines;
	//printf("%d %s %d\n", position, line, n_lines);
	return (TRUE);
}



