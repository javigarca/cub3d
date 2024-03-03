/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:30:47 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/03 12:07:54 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_key_press(t_gamedata *gdata);
int	ft_button_close(t_gamedata *gdata);

int	key_hook(int keycode, t_gamedata *data)
{
	if (keycode == K_ESC)
	{
		ft_exit_game(data, "ESC key pressed.");
		exit(0);
	}
	if (keycode == K_W || keycode == K_AR_U)
		ft_move_forward(data, MOVE_SPEED);
	if (keycode == K_A)
		ft_strafe_left(data, STRAFE_SPEED);
	if (keycode == K_S || keycode == K_AR_D)
		ft_move_backwards(data, MOVE_SPEED);
	if (keycode == K_D)
		ft_strafe_right(data, STRAFE_SPEED);
	if (keycode == K_AR_L)
		ft_rotate_player(data, ROTATION_SPEED);
	if (keycode == K_AR_R)
		ft_rotate_player(data, -ROTATION_SPEED);
	if (keycode == K_SP)
		ft_door_system(data, OFFSET);
	data->pause = FALSE;
	ft_start_draw(data);
	ft_show_menu(data);
	return (keycode);
}

/**
 * Set up the necessary hooks for the game window
 * 
 * @param gdata Pointer to the game data structure
 * 
 * @warning use mlx_hook_key for linux
 * 		mlx_key_hook(gdata->win, key_hook, gdata);
 */
void	ft_start_hooks(t_gamedata *gdata)
{
	mlx_hook(gdata->win, 2, 0, key_hook, gdata);
	mlx_key_hook(gdata->win, key_hook, gdata);
	mlx_hook(gdata->win, 6, 0, ft_mouse_rotation, gdata);
	mlx_hook(gdata->win, 17, 0, ft_button_close, gdata);
}

int	ft_button_close(t_gamedata *gdata)
{
	ft_exit_game(gdata, "Red Button pressed.");
	return (1);
}
