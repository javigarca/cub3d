#include "cube3d.h"

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