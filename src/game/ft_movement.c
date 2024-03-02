/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:31:34 by javi              #+#    #+#             */
/*   Updated: 2024/03/02 10:51:42 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/**
 * Rotate the player's direction by a given rotation speed.
 * 
 * @param gdata The game data structure
 * @param rot_speed The speed of rotation
 */
void	ft_rotate_player(t_gamedata *gdata, double rot_speed)
{
	double	olddirx;
	double	oldplanex;

	olddirx = gdata->player.dir.x;
	gdata->player.dir.x = gdata->player.dir.x * cos(rot_speed) \
					- gdata->player.dir.y * sin(rot_speed);
	gdata->player.dir.y = olddirx * sin(rot_speed) \
					+ gdata->player.dir.y * cos(rot_speed);
	oldplanex = gdata->player.plane.x;
	gdata->player.plane.x = gdata->player.plane.x * cos(rot_speed) \
					- gdata->player.plane.y * sin(rot_speed);
	gdata->player.plane.y = oldplanex * sin(rot_speed) \
						+ gdata->player.plane.y * cos(rot_speed);
}

/**
 * Move the player to the left by a given strafe speed.
 * 
 * @param gdata The game data structure
 * @param strafe_speed The speed of strafing
 */
void	ft_strafe_left(t_gamedata *gdata, double strafe_speed)
{
	t_coord	new;

	new.x = gdata->player.pos.x - (gdata->player.plane.x * strafe_speed);
	new.y = gdata->player.pos.y - (gdata->player.plane.y * strafe_speed);
	if (!(ft_check_collision_x(gdata->map, new.x, gdata->player.pos.y)))
		gdata->player.pos.x = new.x;
	if (!(ft_check_collision_y(gdata->map, gdata->player.pos.x, new.y)))
		gdata->player.pos.y = new.y;
}

/**
 * Move the player to the right by a given strafe speed.
 * 
 * @param gdata The game data structure
 * @param strafe_speed The speed of strafing
 */
void	ft_strafe_right(t_gamedata *gdata, double strafe_speed)
{
	t_coord	new;

	new.x = gdata->player.pos.x + (gdata->player.plane.x * strafe_speed);
	new.y = gdata->player.pos.y + (gdata->player.plane.y * strafe_speed);
	if (!(ft_check_collision_x(gdata->map, new.x, gdata->player.pos.y)))
		gdata->player.pos.x = new.x;
	if (!(ft_check_collision_y(gdata->map, gdata->player.pos.x, new.y)))
		gdata->player.pos.y = new.y;
}

/**
 * Move the player forward by a given movement speed.
 * 
 * @param gdata The game data structure
 * @param movement_speed The speed of movement
 */
void	ft_move_forward(t_gamedata *gdata, double movement_speed)
{
	t_coord	new;

	new.x = gdata->player.pos.x + gdata->player.dir.x * movement_speed;
	new.y = gdata->player.pos.y + gdata->player.dir.y * movement_speed;
	if (!(ft_check_collision_x(gdata->map, new.x, gdata->player.pos.y)))
		gdata->player.pos.x = new.x;
	if (!(ft_check_collision_y(gdata->map, gdata->player.pos.x, new.y)))
		gdata->player.pos.y = new.y;
}

/**
 * Move the player backwards by a given movement speed.
 * 
 * @param gdata The game data structure
 * @param movement_speed The speed of movement
 */
void	ft_move_backwards(t_gamedata *gdata, double movement_speed)
{
	t_coord	new;

	new.x = gdata->player.pos.x - gdata->player.dir.x * movement_speed;
	new.y = gdata->player.pos.y - gdata->player.dir.y * movement_speed;
	if (!(ft_check_collision_x(gdata->map, new.x, gdata->player.pos.y)))
		gdata->player.pos.x = new.x;
	if (!(ft_check_collision_y(gdata->map, gdata->player.pos.x, new.y)))
		gdata->player.pos.y = new.y;
}
