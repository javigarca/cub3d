/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:30:47 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/29 09:50:05 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_key_press(t_gamedata *gdata);
int	ft_button_close(t_gamedata *gdata);

int	key_hook(int keycode, t_gamedata *data)
{
	if (keycode == K_ESC)
	{
		printf("salida de escape. hacer frees\n");
		mlx_destroy_window(data->mlx, data->win); //leaks?
		exit(0);
	}
	if (keycode == K_W || keycode == K_AR_U) // move forward
		ft_move_forward(data, MOVE_SPEED);
	if (keycode == K_A)
		ft_strafe_left(data, STRAFE_SPEED);
	if (keycode == K_S || keycode == K_AR_D) //move back
		ft_move_backwards(data, MOVE_SPEED);
	if (keycode == K_D)
		ft_strafe_right(data, STRAFE_SPEED);
	if (keycode == K_AR_L)
		ft_rotate_player(data, ROTATION_SPEED);
	if (keycode == K_AR_R)
		ft_rotate_player(data, -ROTATION_SPEED);
	if (keycode == K_SP)
		printf("SPACE");
	ft_start_draw(data);
	//printf("salida pos.x = %f pos.y = %f\n", data->player.pos.x, data->player.pos.y);
	return (keycode);
}

void	ft_start_hooks(t_gamedata *gdata)
{
	mlx_hook(gdata->win, 2, 0, key_hook, gdata);
	//mlx_hook(gdata->win, 33, 0L,  ft_key_press, gdata);
	mlx_key_hook(gdata->win, key_hook, gdata);
	mlx_hook(gdata->win, 17, 0, ft_button_close, gdata);
}

int	ft_button_close(t_gamedata *gdata)
{
	(void)gdata;
	//ft_free_map(gdata);
	ft_putstr_fd("\rProgram terminated successfully", 1);
	//close_game(gdata);
	exit (0);
}
