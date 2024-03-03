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
void	ft_show_minimap(t_gamedata *gdata)
{
	t_coord	start;

	start.x = 60;
	start.y = 20;
	ft_minimap(gdata, start);
	mlx_put_image_to_window(gdata->mlx, gdata->win, gdata->img, 0, 0);
}
