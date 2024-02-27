/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:31:34 by javi              #+#    #+#             */
/*   Updated: 2024/02/27 21:33:51 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "game.h"

    // Calcula los nuevos valores de dirección después de la rotación
    // Calcula los nuevos valores del plano de la cámara después de la rotación
void	ft_rotate_player(t_player *player, double rot_speed)
{
    double	oldDirX;
	double	oldPlaneX;

	oldDirX = player->dir.x;
    player->dir.x = player->dir.x * cos(rot_speed) - player->dir.y * sin(rot_speed);
    player->dir.y = oldDirX * sin(rot_speed) + player->dir.y * cos(rot_speed);
    oldPlaneX = player->plane.x;
    player->plane.x = player->plane.x * cos(rot_speed) - player->plane.y * sin(rot_speed);
    player->plane.y = oldPlaneX * sin(rot_speed) + player->plane.y * cos(rot_speed);
}

void ft_strafe_left(t_player *player, double strafe_speed)
{
    player->pos.x -= player->plane.x * strafe_speed;
    player->pos.y -= player->plane.y * strafe_speed;
}

void ft_strafe_right(t_player *player, double strafe_speed)
{
    player->pos.x += player->plane.x * strafe_speed;
    player->pos.y += player->plane.y * strafe_speed;
}
