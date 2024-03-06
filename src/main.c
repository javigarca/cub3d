/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:45:06 by xamayuel          #+#    #+#             */
/*   Updated: 2024/03/06 19:50:09 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"
#include "game_struct.h"
#include "game.h"

/**
 * Main function that initializes the game and starts the gameplay.
 * 
 * @param argn Number of arguments passed to the program
 * @param argv Array of strings containing the arguments
 * 
 * 
 * 		
 */
int	main(int argn, char *argv[])
{
	t_data	*game;

	ft_show_logo();
	if (argn != 2)
		printf(KRED"Error\n"KWHT"CUBE3D:\
				Incorrect number of arguments."KNRM"\n");
	else if (ft_is_valid_input_file(argv) == TRUE)
	{
		printf(KBLU"\nLoading %s ...\n", argv[1]);
		if (ft_is_valid_map(argv[1]) == TRUE)
		{
			printf(KGRN"Parsing %s ...\n"KNRM"", argv[1]);
			game = ft_parse_map(argv[1]);
			if (game != NULL)
			{
				printf(KBLU"Starting Game  ...\n"KNRM"");
				start_the_game(game, argv[1]);
			}
		}
	}
	exit(0);
}
