/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:10:51 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/28 09:50:38 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int *ft_xpm_to_array(t_gamedata *gdata)
{
    int *buffer;

    int x;
    int y;

    int		img_width;
    int 	img_height;



    gdata->img = mlx_xpm_file_to_image(gdata->mlx, "textures/other.xpm", &img_width, &img_height);
    if (!gdata->img)
        printf("Error\nmlx_xpm_file_to_image failed\n");

    buffer = ft_calloc(sizeof(int), gdata->size * gdata->size);
    gdata->addr = (int *)mlx_get_data_addr(gdata->img, &gdata->pixel_b, &gdata->lines_b, &gdata->endian);
    if (!gdata->imgadd)
        printf("Error\nmlx_get_data_addr failed\n");

    y = 0;
    while (y < gdata->size)
    {
        x = 0;
        while (x < gdata->size)
        {
            buffer[y * gdata->size + x] = gdata->addr[y * gdata->size + x];
            printf("\n%d", buffer[y * gdata->size + x]);
            x++;
        }
        printf("\n");
        y++;

    }
    printf("fkdjfkdjf");
    return (buffer);
}

void ft_load_textures(t_gamedata *gdata)
{
	gdata->textures = malloc(sizeof(int *) * 5);
	if (!gdata->textures)
		printf("Error\nMalloc failed\n"); //poner otra forma de salir quitando leaks
	printf("Iniciando texturas\n");
	printf("%s<---\n\n", gdata->map->t_no.texture_path);
	gdata->textures[0] = ft_xpm_to_array(gdata);
}
