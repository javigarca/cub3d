/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_map_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:10:42 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 16:10:51 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

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

