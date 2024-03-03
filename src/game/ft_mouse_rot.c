/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:33:40 by javi              #+#    #+#             */
/*   Updated: 2024/03/02 10:35:25 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/**
 * Rotate the player based on mouse movement.
 * 
 * @param x The x-coordinate of the mouse
 * @param y The y-coordinate of the mouse
 * @param gdata The game data structure
 */
int	ft_mouse_rotation(int x, int y, t_gamedata *gdata)
{
	int		delta;
	int		ypitch;
	double	normdelta;

	ypitch = y - (gdata->img_size.y / 2);
	delta = x - (gdata->img_size.x / 2);
	if (delta != 0)
	{
		normdelta = -delta / (gdata->win_size.x / 2.0);
		ft_rotate_player(gdata, normdelta * MOUSE_SPEED);
	}
	if (ypitch != 0)
	{
		ypitch = fmax(fmin(ypitch, 200.0), -200.0);
		gdata->player.pitch = ypitch * MOUSE_VERTICAL_SPEED;
	}
	ft_start_draw(gdata);
	ft_show_minimap(gdata);
	return (0);
}
