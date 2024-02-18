/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_texture_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:38:58 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/18 11:45:04 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_is_valid_texture_line(const char *direction, const char *line)
{
	char	**data;

	data = ft_split(line, ' ');
	if (ft_2d_array_size(data) != 2)
	{
		free(data);
		return (ft_show_error("To many arguments in line"));
	}
	if (ft_strncmp(data[0], direction, 2) != 0 || ft_strlen(data[0]) != 2)
	{
		free(data);
		return (ft_show_error("Texture direction error"));
	}
	if (ft_is_valid_filename(ft_str_remove_newline(data[1])) == FALSE)
	{
		free(data);
		return (ft_show_error("Texture filename error"));
	}
	free(data);
	return (TRUE);
}
