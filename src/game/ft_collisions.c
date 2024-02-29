/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collisions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:41:12 by javi              #+#    #+#             */
/*   Updated: 2024/02/28 21:41:31 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int ft_check_collision(t_data *map, t_coord new)
{
    int x;
    int y;

    x = (int) new.x;
    y = (int) new.y;
    if (map->map2d[x][y] == '1')
        return (1);
    return (0);
}

int ft_check_doble_col(t_data *map, t_coord new)
{
    t_dot   a;
    //t_dot   b;

    a.x = (int) new.x + (2*OFFSET);
    a.y = (int) new.y + (2*OFFSET);
  //  b.x = (int) new.x - OFFSET;
  //  b.y = (int) new.y - OFFSET;
    if (map->map2d[a.x][a.y] == '1') // || map->map2d[b.x][b.y] == '1')
       return (1);
    return (0);
}