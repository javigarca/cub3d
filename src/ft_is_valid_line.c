/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:10:49 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/18 13:40:24 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int ft_is_color_argument(char *argument);

int	ft_is_valid_map_line(int position, const char *line, int nlines)
{
	if (position == 7 && ft_is_valid_first_map_line(line) == FALSE)
		return (ft_show_error("Invalid first map line.\n"));
	if (position >7 && position < nlines && ft_is_valid_inter_map_line(line) == FALSE)
		return (ft_show_error("Invalid first map line.\n"));
	if (position == nlines && ft_is_valid_last_map_line(line) == FALSE)
		return (ft_show_error("Invalid first map line.\n"));
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
	if (position > 6 && ft_is_valid_map_line(position,line, n_lines) == FALSE)
		return (FALSE);
	return (TRUE);
}

int ft_is_color_line(const char *type, const char *line)
{
	char **data;

	data = ft_split(line,' ');
	if (ft_2d_array_size(data) != 2)
	{
		printf(KRED"ERROR\n"KWHT"CUBE3D: To many arguments in line\n");
		free(data);
		return (FALSE);
	}
	if (ft_strncmp(data[0],type,1) != 0 || ft_strlen(data[0])!=1)
	{
		printf(KRED"ERROR\n"KWHT"CUBE3D: Error in color line\n");
		free(data);
		return (FALSE);	
	}
	if (ft_is_color_argument(data[1]) == FALSE)
	{
		printf(KRED"ERROR\n"KWHT"CUBE3D: Error in color line\n");
		free(data);
		return (FALSE);	

	}

	free(data);
	return (TRUE);
}

int ft_is_color_argument(char *argument)
{
	char **data;
	int  i;

	data = ft_split(argument, ',');
	if (ft_2d_array_size(data) != 3)
	{
		printf(KRED"ERROR\n"KWHT"CUBE3D: Not RGB data\n");
		free(data);
		return (FALSE);
	}
	i = 0;
	while (i < 3)
	{
		if (ft_atoi(data[i]) < 0 || ft_atoi(data[i++]) > 255)
		{
			printf(KRED"ERROR\n"KWHT"CUBE3D: Not RGB data\n");
			free(data);
			return (FALSE);
		}
	}
	free(data);
	return (TRUE);
}