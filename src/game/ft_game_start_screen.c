
#include "game.h"

void ft_game_start_screen(t_gamedata *gdata)
{
	int width;
	int height;
	void *img_ptr;
	
    img_ptr = mlx_xpm_file_to_image(gdata->mlx, "textures/startscreen.xpm", &width, &height);
    mlx_put_image_to_window(gdata->mlx, gdata->win, img_ptr, (W_RESOL - width)/2, (H_RESOL - height) / 2 );
	free(img_ptr);
}