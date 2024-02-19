/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:45:06 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 16:53:16 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "parser.h"
#include "game_struct.h"

t_data* init_data()
{
   
   t_data *data;

	data = ft_calloc(1, sizeof(t_data));
	data->map2d = ft_calloc(10, sizeof(char *)); // init the map
	data->map2d[0] = strdup("1111111111111111111111111"); //fill the map
	data->map2d[1] = strdup("1000000000000000000100001");
	data->map2d[2] = strdup("1001000000000N00001100001");
	data->map2d[3] = strdup("1001000000000000001111101");
	data->map2d[4] = strdup("1001000000000000001000001");
	data->map2d[5] = strdup("1001000000100000001000001");
	data->map2d[6] = strdup("1001000000000000001000001");
	data->map2d[7] = strdup("1001000000001000001000001");
	data->map2d[8] = strdup("1111111111111111111111111");
	data->map2d[9] = NULL;

	data->c_celing.r = 250;
	data->c_celing.g = 0;
	data->c_celing.b = 127;

	data->c_floor.r = 250;
	data->c_floor.g = 0;
	data->c_floor.b = 127;

	data->p_x = 100;
	data->p_x = 200;

	data->w_map = 1920;
	data->h_map = 1080;

	data->t_no.texture_path = ft_strdup("textures/barrel.xpm");
	data->t_so.texture_path = ft_strdup("textures/barrel.xpm");
	data->t_we.texture_path = ft_strdup("textures/barrel.xpm");
	data->t_ea.texture_path = ft_strdup("textures/barrel.xpm");
	return (data);
}
int ft_find_right_wall(char **map2d, int row, int col)
{
	while (map2d[row][col]!='1')
	{
		col++;
	}
	return (col);
}
typedef struct {
    int row;
    int col;
} t_pos;

t_pos ft_go_up(char **map2, int row, int col)
{
	t_pos pos;

	pos.row = row;
	pos.col = col;

	while ( pos.row >0)
	{
		printf("estamos en %d %d ", pos.row,  pos.col);
		if (map2[ pos.row-1][ pos.col] == '1')
		{
			 pos.row--;
			printf("caso vertical\n");
		}
		else if (map2[ pos.row][ pos.col-1] == '1')
		{
			 pos.col --;
			printf("caso horizontal izq\n");
		}		
		else if (map2[ pos.row-1][ pos.col-1] == '1')
		{
			printf("caso diagonoal\n");
			pos.col--;
			row--;
		}
		else if (map2[ pos.row][ pos.col+1] == '1')
		{
			 pos.col ++;
			printf("caso horizontal dcha\n");
		}		
		else
		{
			pos.row = -1;
		    pos.row = -1;
			return (pos);
		}
			
	}
	return( pos);
}
int ft_check_closed_map(t_data *game)
{
	int row;
	int col;
	t_pos pos;

	row = 7;
	col = 4;
	col = ft_strlen(game->map2d[row]) - 1;
	printf("EMPEZAMOS EN %d %d con valor %c \n", row, col, game->map2d[row][col]);
	pos = ft_go_up(game->map2d, row, col);
	printf("Se puede ir arriba hasta [%d][%d] \n", pos.row, pos.col);
	return (TRUE);
}
int	main(int argn, char *argv[])
{
	t_data	*game;
	
	if (argn != 2)
		printf(KRED"Error\n"KWHT"CUBE3D:\
				Incorrect number of arguments."KNRM"\n");
	else if (ft_is_valid_input_file(argv) == TRUE)
	{
		printf(KBLU"\nLoading %s ...\n",argv[1]);
		printf(KNRM);
		if (ft_is_valid_map(argv[1]) == TRUE)
		{
			game = init_data();
			printf("%d",ft_check_closed_map(game));
			//game = ft_parse_map(argv[1]);
			printf("%d\n", game->c_celing.b);
			
			printf("%s\n", game->t_no.texture_path);
			// start_the_game(game); 
		}
	}
	exit(0);
}
