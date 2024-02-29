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
    int deltaX = x - (gdata->img_size.x / 2);
    int deltaY = y - (gdata->img_size.y / 2);
    if (deltaY)
        deltaY = 0;
    // Aquí, podrías usar deltaX para ajustar la rotación del jugador
    // La rotación puede ser más sensible o menos sensible dependiendo de deltaX
    // Por ejemplo, rotar proporcionalmente a deltaX
    if (deltaX != 0) {
        ft_rotate_player(gdata, deltaX * ROTATION_SPEED);
        printf("ROTORATON");
    }

    // Opcional: Re-centrar el cursor del ratón para evitar salir de la ventana
    // mlx_mouse_move(data->mlx, data->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    return 0;
}