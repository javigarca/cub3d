/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:19:15 by xamayuel          #+#    #+#             */
/*   Updated: 2022/05/31 14:08:49 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

/**
 * @brief Function to check -n option in echo builtin (-n -nn -nnnnn)
 * 
 * @param argumen String to chech
 * @return int 
 */
static int	cumple_n(char *argumen)
{
	int	j;

	j = 1;
	if (argumen[0] == '-')
	{
		while (argumen[j])
		{
			if (argumen[j++] != 'n')
				return (0);
		}
	}
	else
		return (0);
	return (1);
}

/**
 * @brief Builtin of "echo" function.
 * 
 * @param argn 
 * @param argv 
 */
int	ft_echo(int argn, char *argv[], int fd)
{
	int	i;
	int	breakline;

	breakline = 1;
	i = 1;
	while (i < argn)
	{
		if (cumple_n(argv[i]) == 1)
		{
			breakline = 0;
			i++;
		}
		else
			break ;
	}
	while (i < (argn - 1))
	{
		ft_putstr_fd(argv[i++], fd);
		ft_putstr_fd(" ", fd);
	}
	if (i < argn)
		ft_putstr_fd(argv[i], fd);
	if (breakline == 1)
		ft_putstr_fd("\n", fd);
	return (0);
}
