/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:53:36 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/02 11:01:39 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

/**
 * Display the game menu on the screen.
 * 
 * @param gdata The game data structure
 */
void	ft_show_menu(t_gamedata *gdata)
{
	t_coord	start;

	start.x = 60;
	start.y = 20;
	mlx_string_put(gdata->mlx, gdata->win, 10, 15, TXT_CLR_A, " CUB3D: ");
	mlx_string_put(gdata->mlx, gdata->win, 65, 15, BKG_CLR_A, " MINI MAP");
	ft_minimap(gdata, start);
	mlx_put_image_to_window(gdata->mlx, gdata->win, gdata->img, 0, 0);
}
