/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:33:40 by javi              #+#    #+#             */
/*   Updated: 2024/02/29 10:33:58 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int ft_mouse_rotation(int x, int y, t_gamedata *gdata)
{

    int delta;
    int ypitch;
    double normdelta;
    
    ypitch = y - (gdata->img_size.y /2);
    delta = x - (gdata->img_size.x / 2);
    if (delta != 0)
     {
        normdelta = -delta / (gdata->win_size.x / 2.0);
      //  printf("Rotating: normdelta=%f, rot_speed=%f\n", normdelta, MOUSE_SPEED);

        ft_rotate_player(gdata, normdelta * MOUSE_SPEED);
    }
    if (ypitch != 0)
    {
        ypitch = fmax(fmin(ypitch, 200.0), -200.0);
        gdata->player.pitch = ypitch * MOUSE_VERTICAL_SPEED;
    }
    //printf("\n pitch: %f", gdata->player.pitch);
    ft_start_draw(gdata);
	ft_show_menu(gdata, "ALOHA"); //CAMBIAR SI QUEREMOS MOSTRAR MAPA
    mlx_mouse_move(gdata->mlx, gdata->win, gdata->win_size.x / 2, gdata->win_size.y / 2);
    return 0;
}
