/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:45:06 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/17 23:25:40 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int argn, char *argv[])
{
	if (argn != 2)
		printf(KRED"Error\n"KWHT"CUBE3D:\
				Incorrect number of arguments."KNRM"\n");
	else if (ft_is_valid_arguments(argv) == TRUE)
	{
		printf(KGRN"\nLoading map.....\n"KNRM);
		ft_is_valid_map(argv[1]);
	}
	exit(0);
}
