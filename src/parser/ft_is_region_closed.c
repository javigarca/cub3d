/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_region_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:36:48 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/21 22:45:46 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	isborder(int x, int y, int rows, int cols);
static bool	floodfillutil(char **pantalla, int x, int y, bool *isClosed, int rows);
static char	**ft_copy_map_data(t_data data, int rows);
static void	print_pantalla(char **pantalla, int rows);

bool	ft_is_region_closed(t_data data, char *filename)
{
	bool	isclosed;
	int		rows;
	char	**pantalla;

	isclosed = true;
	rows = ft_count_map_lines(filename);
	pantalla = ft_copy_map_data(data, rows);
	printf("rows %d\n", rows);
	printf("columns %d\n", (int)ft_strlen(pantalla[0]));
	pantalla[data.p_x][data.p_y] = '0';
	floodfillutil(pantalla, data.p_x, data.p_y, &isclosed, rows);
	print_pantalla(pantalla, rows);
	return (isclosed);
}

static bool	isborder(int x, int y, int rows, int cols)
{
	return (x == 0 || x == (rows - 1) || y == 0 || y == (cols - 2));
}

static bool	floodfillutil(char **pantalla, int x, int y, bool *isclosed, int rows)
{
	if (x < 0 || x > (rows - 1))
		return (false);
	if (y < 0 || y > (int)ft_strlen(pantalla[x]) - 2)
		return (false);
	if (pantalla[x][y] == 'H')
	{
		*isclosed = false;
	}
	else if (pantalla[x][y] != '0')
		return (true);
	if (isborder(x, y, rows, (int)ft_strlen(pantalla[x])))
	{
		*isclosed = false;
	}
	pantalla[x][y] = 'C';
	floodfillutil(pantalla, x + 1, y, isclosed, rows);
	floodfillutil(pantalla, x - 1, y, isclosed, rows);
	floodfillutil(pantalla, x, y -1, isclosed, rows);
	floodfillutil(pantalla, x, y +1, isclosed, rows);
	return (*isclosed);
}

static char	**ft_copy_map_data(t_data data, int rows)
{
	char	**pantalla;
	int		i;
	int		j;

	pantalla = ft_calloc(rows, sizeof(char *));
	i = 0;
	while (i < rows)
	{
		pantalla[i] = ft_strdup(data.map2d[i]);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < (int)ft_strlen(pantalla[i]))
		{
			if (pantalla[i][j] == ' ')
				pantalla[i][j] = 'H';
			j++;
		}
		i++;
	}
	return (pantalla);
}

static void	print_pantalla(char **pantalla, int rows)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < (int)ft_strlen(pantalla[i]))
		{
			printf("%c", pantalla[i][j]);
			j++;
		}
		i++;
	}
	printf("\n");
}
