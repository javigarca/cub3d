/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:45:06 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/20 13:06:07 by xamayuel         ###   ########.fr       */
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
	data->map2d[0] = strdup("111111111111111111111111"); //fill the map
	data->map2d[1] = strdup("1000000000000000000100001");
	data->map2d[2] = strdup("1001000000000N00001100001");
	data->map2d[3] = strdup("1010000000000000001111001");
	data->map2d[4] = strdup("1010000000000000001000001");
	data->map2d[5] = strdup("1111000000100000001000001");
	data->map2d[6] = strdup("1001000010000000001000001");
	data->map2d[7] = strdup("1001000011110000001000001");
	data->map2d[8] = strdup("1111111110011111111111111");
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
void ft_print(t_data data)
{
	int map_lines;
	int cont;

	cont = 0;
	printf("IMPRIMENDO T_DATA\n");
	printf("TEXTURES\n");
	printf("NO: %s", data.t_no.texture_path);
	printf("SO: %s", data.t_so.texture_path);
	printf("WE: %s", data.t_we.texture_path);
	printf("EA: %s", data.t_ea.texture_path);
	printf("------------------------------\n");
	printf("FLOOR: %d,%d,%d\n", data.c_floor.r,data.c_floor.g,data.c_floor.b);
	printf("CEILING: %d,%d,%d\n", data.c_celing.r,data.c_celing.g,data.c_celing.b);
	printf("------------------------------\n");
	printf("PLAYER ARRAY POSITION: %d %d\n", data.p_x,data.p_y);
	printf("PLAYER DIRECTION: %c\n", data.map2d[data.p_x][data.p_y]);
	printf("------------------------------\n");
	map_lines = ft_2d_array_size(data.map2d);
	while (cont < map_lines)
	{
		printf("%s", data.map2d[cont++]);
	}
	printf("\n");
}

void	ft_show_logo()
{
	printf(""KBLU"  ______  __    __ _______  ________ ");
	printf(KMAG" ______  _______  \n");
	printf(KBLU" /      \\/  |  /  /       \\/        |");
	printf(KMAG"/      \\/       \\ \n");
	printf(KBLU"/$$$$$$  $$ |  $$ $$$$$$$  $$$$$$$$/");
	printf(KMAG"/$$$$$$  $$$$$$$  |\n");
	printf(KBLU"$$ |  $$/$$ |  $$ $$ |__$$ $$ |__   ");
	printf(KMAG"$$ ___$$ $$ |  $$ |\n");
	printf(KBLU"$$ |     $$ |  $$ $$    $$<$$    |    ");
	printf(KMAG"/   $$<$$ |  $$ |\n");
	printf(KBLU"$$ |   __$$ |  $$ $$$$$$$  $$$$$/    ");
	printf(KMAG"_$$$$$  $$ |  $$ |\n");
	printf(KBLU"$$ \\__/  $$ \\__$$ $$ |__$$ $$ |_____");
	printf(KMAG"/  \\__$$ $$ |__$$ |\n");
	printf(KBLU"$$    $$/$$    $$/$$    $$/$$       ");
	printf(KMAG"$$    $$/$$    $$/ \n");
	printf(KBLU" $$$$$$/  $$$$$$/ $$$$$$$/ $$$$$$$$/ ");
	printf(KMAG"$$$$$$/ $$$$$$$/\n");
	printf(KYEL"@Unai Amayuelas "KGRN"\t(A.K.A xamayuel)\n");
	printf(KYEL"@Javier García Arango "KGRN"\t(A.K.A javigarc)\n"KWHT);
}

int	main(int argn, char *argv[])
{
	t_data	*game;
	
	if (argn != 2)
		printf(KRED"Error\n"KWHT"CUBE3D:\
				Incorrect number of arguments."KNRM"\n");
	else if (ft_is_valid_input_file(argv) == TRUE)
	{
		ft_show_logo();
		printf(KBLU"\nLoading %s ...\n",argv[1]);
		printf(KNRM);
		if (ft_is_valid_map(argv[1]) == TRUE)
		{
			//game = init_data();
			
			game = ft_parse_map(argv[1]);
			ft_print(*game);
			//printf("%d",ft_check_closed_map(game));
			//printf("%d\n", game->c_celing.b);
			
			//printf("%s\n", game->t_no.texture_path);
			// start_the_game(game); 
		}
	}
	exit(0);
}
