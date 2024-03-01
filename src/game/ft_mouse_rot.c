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
    // Calcular la diferencia de movimiento desde el centro de la ventana
    int delta;
    double normdelta;
    (void)y;
    
    delta = x - (gdata->img_size.x / 2);
    if (delta != 0) {
        normdelta = delta / (gdata->win_size.x / 2.0);
        printf("Rotating: normdelta=%f, rot_speed=%f\n", normdelta, MOUSE_SPEED);

        ft_rotate_player(gdata, normdelta * MOUSE_SPEED);
    }
    ft_start_draw(gdata);
	ft_show_menu(gdata, "ALOHA"); //CAMBIAR SI QUEREMOS MOSTRAR MAPA
    mlx_mouse_move(gdata->mlx, gdata->win, gdata->win_size.x / 2, gdata->win_size.y / 2);
    return 0;
}
