/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:28:25 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/21 15:00:41 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "game_struct.h"


void	ft_free_data(t_data *data)
{
	int	i;

	if (!data)
		return;

	// Liberar el arreglo map2d si existe.
	if (data->map2d)
	{
		i = 0;
		while (data->map2d[i])
		{
			free(data->map2d[i]); // Liberar cada cadena dentro del arreglo.
			i++;
		}
		free(data->map2d); // Luego, liberar el arreglo en sí.
	}

	// Aquí puedes agregar la liberación de otros campos si es necesario.
	// Por ejemplo, si tienes campos de texto que también fueron asignados dinámicamente:
	free(data->t_no.texture_path);
	free(data->t_so.texture_path);
	free(data->t_we.texture_path);
	free(data->t_ea.texture_path);

	free(data); // Finalmente, liberar la estructura t_data en sí.
}