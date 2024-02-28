/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:31:34 by javi              #+#    #+#             */
/*   Updated: 2024/02/28 19:02:55 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_rotate_player(t_gamedata *gdata, double rot_speed)
{
	double	olddirx;
	double	oldplanex;

	olddirx = gdata->player.dir.x;
	gdata->player.dir.x = gdata->player.dir.x * cos(rot_speed) \
					- gdata->player.dir.y * sin(rot_speed);
	gdata->player.dir.y = olddirx * sin(rot_speed) + gdata->player.dir.y * cos(rot_speed);
	oldplanex = gdata->player.plane.x;
	gdata->player.plane.x = gdata->player.plane.x * cos(rot_speed) \
					- gdata->player.plane.y * sin(rot_speed);
	gdata->player.plane.y = oldplanex * sin(rot_speed) \
						+ gdata->player.plane.y * cos(rot_speed);
}

void	ft_strafe_left(t_gamedata *gdata, double strafe_speed)
{
	t_coord new;

	new.x = gdata->player.pos.x - gdata->player.plane.x * strafe_speed - gdata->player.dir.x * OFFSET;
	new.y = gdata->player.pos.y - gdata->player.plane.y * strafe_speed - gdata->player.dir.y * OFFSET;
	if (ft_check_collision(gdata->map, new) == 0)
	{
		gdata->player.pos.x = new.x;
		gdata->player.pos.y = new.y;
	}
}

void	ft_strafe_right(t_gamedata *gdata, double strafe_speed)
{
	t_coord new;

	new.x = gdata->player.pos.x + gdata->player.plane.x * strafe_speed + gdata->player.dir.x * OFFSET;
	new.y = gdata->player.pos.y + gdata->player.plane.y * strafe_speed + gdata->player.dir.y * OFFSET;
	if (ft_check_collision(gdata->map, new) == 0)
	{
		gdata->player.pos.x = new.x;
		gdata->player.pos.y = new.y;
	}
}

void	ft_move_forward(t_gamedata *gdata, double movement_speed)
{
	t_coord new;

	new.x = gdata->player.pos.x + gdata->player.dir.x * movement_speed + gdata->player.dir.x * OFFSET;
	new.y = gdata->player.pos.y + gdata->player.dir.y * movement_speed + gdata->player.dir.y * OFFSET;
	if (ft_check_collision(gdata->map, new) == 0)
	{
		gdata->player.pos.x = new.x;
		gdata->player.pos.y = new.y;
	}
}

void	ft_move_backwards(t_gamedata *gdata, double movement_speed)
{
	t_coord new;
	
	new.x = gdata->player.pos.x - gdata->player.dir.x * movement_speed - gdata->player.dir.x * OFFSET;
	new.y =	gdata->player.pos.y - gdata->player.dir.y * movement_speed - gdata->player.dir.y * OFFSET;
	if (ft_check_collision(gdata->map, new) == 0)
	{
		gdata->player.pos.x = new.x;
		gdata->player.pos.y = new.y;
	}
}
