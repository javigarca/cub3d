/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_region_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:36:48 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/22 10:02:29 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	isborder(int x, int y, int rows, int cols);
static bool	floodfillutil(char **pantalla, int x, int y, bool *isClosed);
static char	**ft_copy_map_data(t_data data, int rows);
static void	print_pantalla(char **pantalla, int rows);

static void free_pantalla(char **pantalla, int rows)
{
    int i = 0;
    while (i < rows) {
        free(pantalla[i]);
        i++;
    }
    free(pantalla);
}

bool	ft_is_region_closed(t_data data, char *filename)
{
	bool	isclosed;
	int		rows;
	char	**pantalla;

	isclosed = true;
	rows = ft_count_map_lines(filename);
	pantalla = ft_copy_map_data(data, rows);
	pantalla[data.p_x][data.p_y] = '0';
	floodfillutil(pantalla, data.p_x, data.p_y, &isclosed);
	if (!isclosed)
		print_pantalla(pantalla, rows);
	free_pantalla(pantalla, rows);
	return (isclosed);
}

static bool	isborder(int x, int y, int rows, int cols)
{
	return (x == 0 || x == (rows - 1) || y == 0 || y == (cols - 2));
}

static bool	floodfillutil(char **pantalla, int x, int y, bool *isclosed)
{
	int	rows;

	rows = ft_2d_array_size(pantalla);
	if (x < 0 || x > (rows - 1))
		return (false);
	if (y < 0 )
		return (false);
	if (y > (int)ft_strlen(pantalla[x]) - 1)
	{
		*isclosed = false;
	}
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
	floodfillutil(pantalla, x + 1, y, isclosed);
	floodfillutil(pantalla, x - 1, y, isclosed);
	floodfillutil(pantalla, x, y -1, isclosed);
	floodfillutil(pantalla, x, y +1, isclosed);
	return (*isclosed);
}

static char	**ft_copy_map_data(t_data data, int rows)
{
	char	**pantalla;
	int		i;
	int		j;

	pantalla = ft_calloc(rows + 1, sizeof(char *));
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
	pantalla[rows] = NULL;
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
			if (pantalla[i][j] == 'C')
				printf("\x1B[31m%s", "▓");
			else if (pantalla[i][j] == '1')
				printf("\x1B[36m%s", "█");
			else 
				printf("%c", pantalla[i][j]);
			j++;
		}
		i++;
	}
	printf("\n");
}
