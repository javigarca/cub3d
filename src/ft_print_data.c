#include "cube3d.h"

void ft_print(t_data data)
{
	int map_lines;
	int cont;
	int col;

	cont = 0;

	printf( KCYN"\t Texture NO   : %s", data.t_no.texture_path);
	printf( KCYN"\t Texture SO   : %s", data.t_so.texture_path);
	printf( KCYN"\t Texture WE   : %s", data.t_we.texture_path);
	printf( KCYN"\t Texture EA   : %s", data.t_ea.texture_path);
	printf( KMAG"\t Floor color  : RGB(%d, %d, %d) \n", data.c_floor.r,data.c_floor.g,data.c_floor.b);
	printf( KMAG"\t Ceiling color: RGB(%d, %d, %d)\n\n", data.c_celing.r,data.c_celing.g,data.c_celing.b);
	printf( "\t INTRODUCED MAP\n\n");

	map_lines = ft_2d_array_size(data.map2d);
	printf("\t ");
	while (cont < map_lines)
	{
		col = 0;
		while(data.map2d[cont][col] !='\0')
		{
			
			if (data.map2d[cont][col] == '1')
				printf(KCYN"%c", data.map2d[cont][col]);
			else if (data.map2d[cont][col] == '0')
				printf(KBLU"%c", data.map2d[cont][col]);
			else
				printf(KRED"%c", data.map2d[cont][col]);
			col++;
		}
		printf(""KNRM);
		cont++;
		printf("\t ");
	}
	printf("\n\n\n");
}