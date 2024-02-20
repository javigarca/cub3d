/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:45:06 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/20 14:19:54 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "parser.h"
#include "game_struct.h"

int	main(int argn, char *argv[])
{
	t_data	*game;
	
	if (argn != 2)
		printf(KRED"Error\n"KWHT"CUBE3D:\
				Incorrect number of arguments."KNRM"\n");
	else if (ft_is_valid_input_file(argv) == TRUE)
	{
		ft_show_logo();
		printf(KBLU"\nLoading %s ...\n",argv[1]);
		if (ft_is_valid_map(argv[1]) == TRUE)
		{
			printf(KGRN"Parsing %s ...\n"KNRM"",argv[1]);
			game = ft_parse_map(argv[1]);
			if (game != NULL)
			{
				ft_print(*game);
				free(game);
			}
				
			//printf("%d",ft_check_closed_map(game));
			//printf("%d\n", game->c_celing.b);
			
			//printf("%s\n", game->t_no.texture_path);
			// start_the_game(game); 
			
		}
	}
	exit(0);
}
