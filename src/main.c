/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:45:06 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/21 14:03:43 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "parser.h"
#include "game_struct.h"

int	main(int argn, char *argv[])
{
	t_data	*game;
	
	ft_show_logo();
	if (argn != 2)
		printf(KRED"Error\n"KWHT"CUBE3D:\
				Incorrect number of arguments."KNRM"\n");
	else if (ft_is_valid_input_file(argv) == TRUE)
	{
		printf(KBLU"\nLoading %s ...\n",argv[1]);
		if (ft_is_valid_map(argv[1]) == TRUE)
		{
			printf(KGRN"Parsing %s ...\n"KNRM"",argv[1]);
			(void)game;
			//game = ft_parse_map(argv[1]);
			//if (game != NULL)
			//{
			//	ft_print(*game);
			//	free(game);
			//}
				
			//printf("%d",ft_check_closed_map(game));
			//printf("%d\n", game->c_celing.b);
			
			//printf("%s\n", game->t_no.texture_path);
			// start_the_game(game); 
			
		}
	}
	exit(0);
}
int		main2(int argc, char *argv[])
{
	int	fd1;
	char	*line;

	fd1 = open(argv[1], O_RDONLY);
	if (argc > 1)
	{
		while ((line = get_next_line(fd1)))
		{
			printf("%s\n", line);
			free(line);
		}
		close(fd1);
	}
	system("leaks -quiet cub3d");
	return (0);
}
int main3(int argc, char *argv[])
{
	char	*line;
	int		fd;
	int		pos;

	(void)argc;
	pos = 1;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		
		pos++;
	}
	close(fd);

	return (pos - 1);
}
