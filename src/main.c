/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:45:06 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/17 15:44:50 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
int ft_is_valid_file_extension(const char *filename)
{
	int len;

	len =ft_strlen(filename);
	if (len < 4)
	{
		printf("\x1B[31mERROR\n"KWHT"CUBE3D: Map filename too short."KNRM"\n");
		return (FALSE);
	}
	if (ft_strncmp(filename+len-4,".cub",4)==0)
		return (TRUE);
	printf(KRED"ERROR\n"KWHT"CUBE3D: Incorrect filename extension."KNRM"\n");	
	return (FALSE);
}


int ft_is_valid_filename(const char *filename)
{
	int fd;
	// Abrir el fichero en modo lectura
	fd = open(filename, O_RDONLY);

	if (fd == -1) {
	perror(KRED"Error\n"KWHT"CUBE3D");
	return (FALSE);
	}
	if (close(fd) == -1) {
	perror(KRED"Error\n"KWHT"CUBE3D");
	return (FALSE);
	}
	return (TRUE);

}
int ft_is_valid_arguments(char *arguments[])
{
	if (ft_is_valid_file_extension(arguments[1]) == FALSE)
		return (FALSE);
	if (ft_is_valid_filename(arguments[1]) == FALSE)
		return (FALSE);
	return (TRUE);
}
int	main(int argn, char *argv[])
{
	if (argn != 2)
		printf("\x1B[31mERROR\n"KWHT"CUBE3D:Incorrect number of arguments."KNRM"\n");
	else if (ft_is_valid_arguments(argv) == TRUE)
	{
		printf("\n puede comenzar el juego\n");
	}
	return (0);
}
