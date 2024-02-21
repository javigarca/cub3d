/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:28:25 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/21 22:10:25 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"

void	ft_free_data(t_data *data)
{
	int	i;

	if (!data)
		return ;
	if (data->map2d)
	{
		i = 0;
		while (data->map2d[i])
		{
			free(data->map2d[i]);
			i++;
		}
		free(data->map2d);
	}
	free(data->t_no.texture_path);
	free(data->t_so.texture_path);
	free(data->t_we.texture_path);
	free(data->t_ea.texture_path);
	free(data);
}
