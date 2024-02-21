/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:45:06 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/21 17:46:19 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "parser.h"
#include "game_struct.h"
#include <stdbool.h>


bool isBorder(int x, int y ,int rows, int cols)
{

	 return x == 0 || x == (rows - 1)  || y == 0 || y == (cols - 2);
}

bool floodFillUtil(char **pantalla, int x, int y, bool *isClosed, int rows)
{
	if (x < 0 || x > (rows - 1))
		return false;
	if (y < 0 || y > (int)ft_strlen(pantalla[x]) - 2)
		return false;
	if (pantalla[x][y] == 'H')
	{
		*isClosed = false;;
	}
	else if (pantalla[x][y] != '0')
			return true;
	
		
	if (isBorder(x,y, rows, (int)ft_strlen(pantalla[x])))
	{
		*isClosed = false;
	}
	pantalla[x][y] = 'C';
	floodFillUtil(pantalla, x+1, y, isClosed, rows);
	floodFillUtil(pantalla, x-1, y, isClosed, rows);
	floodFillUtil(pantalla, x, y -1, isClosed, rows);
	floodFillUtil(pantalla, x, y +1, isClosed, rows);
	return *isClosed;	
}
bool ft_is_region_closed(t_data data, char *filename)
{
	bool isClosed;
	int rows;
	char **pantalla;
	int i;
	
	isClosed = true;
	
	rows = ft_count_map_lines(filename);
	
	pantalla = ft_calloc(rows, sizeof(char*));
	i = 0;
	while (i < rows)
	{
		pantalla[i] =ft_strdup(data.map2d[i]);
		i++;
	}
	for (int i = 0; i < rows ; i++) {
        for (int j = 0; j < (int)ft_strlen(pantalla[i]); j++)
		{
			if (pantalla[i][j] == ' ')
				pantalla[i][j] = 'H';
		}
	}
            
	printf("rows %d\n",rows);
	printf("columns %d\n", (int)ft_strlen(pantalla[0]));
	pantalla[data.p_x][data.p_y] = '0';
	floodFillUtil(pantalla, data.p_x, data.p_y,&isClosed, rows);
	 // Imprime la pantalla
	 printf("----- %d ----\n", (int)ft_strlen(pantalla[0]));
    for (int i = 0; i < rows ; i++) {
        for (int j = 0; j < (int)ft_strlen(pantalla[i]); j++)
            printf("%c", pantalla[i][j]);
		
	}
	printf("\n");
	
	return isClosed;

}
int	main(int argn, char *argv[])
{
	t_data	*game;
	
	ft_show_logo();
	if (argn != 2)
		printf(KRED"Error\n"KWHT"CUBE3D:\
				Incorrect number of arguments."KNRM"\n");
	else if (ft_is_valid_input_file(argv) == TRUE)
	{
		printf(KBLU"\nLoading %s ...\n",argv[1]);
		if (ft_is_valid_map(argv[1]) == TRUE)
		{
			printf(KGRN"Parsing %s ...\n"KNRM"",argv[1]);
			
			game = ft_parse_map(argv[1]);
			if (game != NULL)
			{
				ft_print(*game);
				if (ft_is_region_closed(*game, argv[1]))
					printf("REGION CERRADA\n");
				else
					printf("REGION ABIERTA\n");
				ft_print(*game);
				ft_free_data(game);
			}
				
			//printf("%d",ft_check_closed_map(game));
			//printf("%d\n", game->c_celing.b);
			
			//printf("%s\n", game->t_no.texture_path);
			// start_the_game(game); 
			
		}
	}
	system("leask cube3d");
	exit(0);
}
