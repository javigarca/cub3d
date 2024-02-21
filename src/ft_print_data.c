/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:16:05 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/21 12:21:18 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	ft_print_map(char **map2d);

void	ft_print(t_data data)
{
	printf(KCYN"\t Texture NO   : %s", data.t_no.texture_path);
	printf(KCYN"\t Texture SO   : %s", data.t_so.texture_path);
	printf(KCYN"\t Texture WE   : %s", data.t_we.texture_path);
	printf(KCYN"\t Texture EA   : %s", data.t_ea.texture_path);
	printf(KMAG"\t Floor color  : ");
	printf("RGB(%d, %d, %d) \n", data.c_floor.r, data.c_floor.g, data.c_floor.b);
	printf(KMAG"\t Ceiling color: ");
	printf("RGB(%d, %d, %d)\n\n", data.c_celing.r, data.c_celing.g, data.c_celing.b);
	printf("\t INTRODUCED MAP\n\n");
	ft_print_map(data.map2d);
	printf("\n");
}

static void	ft_print_map(char **map2d)
{
	int	cont;
	int	col;
	int	map_lines;

	cont = 0;
	map_lines = ft_2d_array_size(map2d);
	printf("\t ");
	while (cont < map_lines)
	{
		col = 0;
		while (map2d[cont][col] != '\0')
		{
			if (map2d[cont][col] == '1')
				printf(KCYN"%c", map2d[cont][col]);
			else if (map2d[cont][col] == '0')
				printf(KBLU"%c", map2d[cont][col]);
			else
				printf(KRED"%c", map2d[cont][col]);
			col++;
		}
		cont++;
		printf("\t ");
	}
}
